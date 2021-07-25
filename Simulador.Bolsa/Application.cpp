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
int num = 0;
void Application::onCreate(const FIX::SessionID&) {}

void Application::onLogon(const FIX::SessionID&) {}

void Application::onLogout(const FIX::SessionID&) {}

void Application::toAdmin(FIX::Message&, const FIX::SessionID&)
{
}

void Application::toApp(FIX::Message&, const FIX::SessionID&)
{
}

void Application::fromAdmin(const FIX::Message&, const FIX::SessionID&)
{
}

void Application::fromApp(const FIX::Message& message, const FIX::SessionID& sessionID)
{

	crack(message, sessionID);
}

void Application::onMessage(const FIX42::NewOrderSingle& message, const FIX::SessionID&) // New order message
{
	// Fix NewOrderSingle class instances:
	// (https://www.onixs.biz/fix-dictionary/4.2)
	FIX::SenderCompID senderCompID;		// Sender ID
	FIX::TargetCompID targetCompID;		// Target ID
	FIX::Symbol symbol;					// Symbol
	FIX::ClOrdID clOrdID;				// Order ID
	FIX::Side side;						// Order side
	FIX::OrdType ordType;				// Order type
	FIX::Price price;					// Order price
	FIX::OrderQty orderQty;				// Order quantity 
	FIX::TimeInForce timeInForce		// Specifies how long the order remains in effect
	(FIX::TimeInForce_DAY);				// Time in force Spec

	// Message get properties
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

void Application::onMessage(const FIX42::OrderCancelRequest&, const FIX::SessionID&) // Order cancel request message
{
}

void Application::onMessage(const FIX42::MarketDataRequest&, const FIX::SessionID&) // MakertData request message
{
}
void Application::sendOrder(const Order& order)
{
	if (_repoController.addOrder(order)) 
	{
		std::queue<Order> orders;
		_repoController.matchOrder(orders);
		num += 1;
		FIX42::ExecutionReport report
		(
			FIX::OrderID(order.getClientID()),
			FIX::ExecID(std::to_string(num)),
			FIX::ExecTransType('0'),
			FIX::ExecType('0'),
			FIX::OrdStatus('0'),
			FIX::Symbol(order.getSymbol()),
			FIX::Side(order.getSide()),
			FIX::LeavesQty(order.getTotalPrice()),
			FIX::CumQty(order.getTotalPrice()),
			FIX::AvgPx(order.getTotalPrice())
		);
		
		FIX::Session::sendToTarget(report, FIX::SenderCompID(order.getTarget()), FIX::TargetCompID(order.getOwner()));
	}
	
}


