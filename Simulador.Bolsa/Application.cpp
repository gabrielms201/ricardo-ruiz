#include "quickfix/Application.h"
#include "Application.h"
#include "quickfix/Session.h"
#include "quickfix/config-all.h"
#include "quickfix/fix42/ExecutionReport.h"
#include "Order.h"
#include "quickfix/Application.h"
#include "quickfix/MessageCracker.h"
#include "quickfix/Values.h"
#include "quickfix/Utility.h"
#include "quickfix/Mutex.h"
// FIX Setup
void Application::onCreate(const FIX::SessionID&) {}

void Application::onLogon(const FIX::SessionID&) {}

void Application::onLogout(const FIX::SessionID&) {}

void Application::toAdmin(FIX::Message&, const FIX::SessionID&) {}

void Application::toApp(FIX::Message&, const FIX::SessionID&) {}

void Application::fromAdmin(const FIX::Message&, const FIX::SessionID&) {}

void Application::fromApp(const FIX::Message& message, const FIX::SessionID& sessionID)
{
	crack(message, sessionID);
}

// Fix Messages (https://www.onixs.biz/fix-dictionary/4.2/msgs_by_msg_type.html)
void Application::onMessage(const FIX42::NewOrderSingle& message, const FIX::SessionID&) // New order message
{
	// Fix NewOrderSingle class atributes instances:
	// (https://www.onixs.biz/fix-dictionary/4.2) - (https://www.onixs.biz/fix-dictionary/4.2/msgtype_d_68.html)
	FIX::SenderCompID senderCompID;		// Sender ID
	FIX::TargetCompID targetCompID;		// Target ID
	FIX::Symbol symbol;					// Symbol
	FIX::ClOrdID clOrdID;				// Order ID
	FIX::Side side;						// Order side
	FIX::OrdType ordType;				// Order type
	FIX::Price price;					// Order price
	FIX::OrderQty orderQty;				// Order quantity
	FIX::TimeInForce timeInForce		// Specifies how long the order remains in effect
	('0');				// Time in force Spec
	// Message get methods
	message.getHeader().get(senderCompID);
	message.getHeader().get(targetCompID);
	message.get(symbol);
	message.get(clOrdID);
	message.get(side);
	message.get(ordType);
	message.get(price);
	message.get(orderQty);
	message.get(timeInForce);
	// Create Order:
	Order order(senderCompID, targetCompID, symbol, clOrdID, side, ordType, price, orderQty);
	// Send order to repository
	sendOrder(order);
}
void Application::onMessage(const FIX42::OrderCancelRequest& message, const FIX::SessionID&) // OrderCancelRequest message
{
	// Fix OrderCancelRequest class atributes instances:
	// (https://www.onixs.biz/fix-dictionary/4.2) - (https://www.onixs.biz/fix-dictionary/4.2/msgtype_f_70.html)
	FIX::OrigClOrdID origClOrdID;		// Order id of the previous order
	FIX::Side side;						// Order side
	// Message get methods
	message.get(origClOrdID);
	message.get(side);
	// Cancel order:
	cancelOrder(side, origClOrdID);
}

// Order methods
int execId = 0;
void Application::sendOrder(const Order& order)
{
	if (_repoController.addOrder(order))
	{
		std::queue<Order> orders;
		_repoController.matchOrder(orders);
		execId += 1;
		FIX42::ExecutionReport report
		(
			FIX::OrderID(order.getClientID()),
			FIX::ExecID(std::to_string(execId)),
			FIX::ExecTransType('0'),					// char 0 = (new) status
			FIX::ExecType('0'),
			FIX::OrdStatus('0'),
			FIX::Symbol(order.getSymbol()),
			FIX::Side(order.getSide()),
			FIX::LeavesQty(order.getTotalPrice()),
			FIX::CumQty(order.getTotalPrice()),
			FIX::AvgPx(order.getAveragePrice())
		);
		FIX::Session::sendToTarget(report, FIX::SenderCompID(order.getTarget()), FIX::TargetCompID(order.getOwner()));
	}
	else refuseOrder(order);
}
void Application::refuseOrder(const Order& order)
{
	execId += 2;
	FIX42::ExecutionReport report
	(
		FIX::OrderID(order.getClientID()),
		FIX::ExecID(std::to_string(execId)),
		FIX::ExecTransType('8'),						// char 8 = (refused) status
		FIX::ExecType('8'),
		FIX::OrdStatus('8'),
		FIX::Symbol(order.getSymbol()),
		FIX::Side(order.getSide()),
		FIX::LeavesQty(order.getTotalPrice()),
		FIX::CumQty(order.getTotalPrice()),
		FIX::AvgPx(order.getAveragePrice())
	);
	FIX::Session::sendToTarget(report, FIX::SenderCompID(order.getTarget()), FIX::TargetCompID(order.getOwner()));
}
void Application::cancelOrder(const char side, const std::string& id)
{
	Order& order = _repoController.findOrder(side, id);
	execId += 3;
	FIX42::ExecutionReport report
	(
		FIX::OrderID(id),
		FIX::ExecID(std::to_string(execId)),
		FIX::ExecTransType('4'),						// char 4 = (canceled) status
		FIX::ExecType('4'),
		FIX::OrdStatus('4'),
		FIX::Symbol(order.getSymbol()),
		FIX::Side(order.getSide()),
		FIX::LeavesQty(order.getTotalPrice()),
		FIX::CumQty(order.getTotalPrice()),
		FIX::AvgPx(order.getAveragePrice())
	);
	FIX::Session::sendToTarget(report, FIX::SenderCompID(order.getTarget()), FIX::TargetCompID(order.getOwner()));
	_repoController.deleteOrder(order);
}
