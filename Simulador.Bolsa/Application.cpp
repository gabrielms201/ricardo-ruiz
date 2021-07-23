#include "quickfix/Application.h"
#include "Application.h"
#include "quickfix/Session.h"
#include "quickfix/config-all.h"
#include "quickfix/fix42/ExecutionReport.h"
#include ""



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
	// Fix NewOrder class instances:
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

}

void Application::onMessage(const FIX42::OrderCancelRequest&, const FIX::SessionID&) // Order cancel request message
{
}

void Application::onMessage(const FIX42::MarketDataRequest&, const FIX::SessionID&) // MakertData request message
{
}
