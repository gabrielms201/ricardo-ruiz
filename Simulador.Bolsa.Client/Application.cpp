#include "Application.h"
#include <iostream>
#include "quickfix/MessageCracker.h"


// FIX Setup
void Application::onCreate(const FIX::SessionID&) {}

void Application::onLogon(const FIX::SessionID&) {}

void Application::onLogout(const FIX::SessionID&) {}

void Application::toAdmin(FIX::Message&, const FIX::SessionID&) {}

void Application::toApp(FIX::Message& , const FIX::SessionID&) {
}

void Application::fromAdmin(const FIX::Message&, const FIX::SessionID&) {}

void Application::fromApp(const FIX::Message& message, const FIX::SessionID& sessionID)
{
	crack(message, sessionID);
}
void Application::onMessage (const FIX42::ExecutionReport&, const FIX::SessionID&) {}
void Application::onMessage (const FIX42::OrderCancelReject&, const FIX::SessionID&) {}

void Application::runClient()
{
	while (true)
	{
		char operation = mainMenu();
		switch (operation) 
		{
			case '1':
				return addOrder();
			case '2':
				return deleteOrder();
			case '3':
				return listOrders();
			case '4':
				break;
		}
		break;
	}
}
char Application::mainMenu()
{
	char input;
	std::cout
		<< "\nBem vindo ao simulador de ordem de compras! O que voce deseja fazer?\n"
		<< std::endl
		<< "1-) Nova ordem de compra\n"
		<< "2-) Cancelar ordem de compra\n"
		<< "3-) Ver ordens\n"
		<< "4-) Sair\n";
	std::cin >> input;
	switch (input)
	{
	case '1':
		return input;
	case '2':
		return input;
	case '3':
		return input;
	case '4':
		return input;
	default:
		std::cout << "Opcao desconhecida! Tente novamente\n";
		break;
	}
}

void Application::addOrder()
{
	float quantityValue, priceValue;
	std::string symbolValue;
	// Input
	std::cout << "Digite a quantidade:" << std::endl;
	std::cin >> quantityValue;
	std::cout << "Digite o preco:" << std::endl;
	std::cin >> priceValue;
	std::cout << "Digite o simbolo:" << std::endl;
	std::cin >> symbolValue;
	//	Variables
	ordID += 1;
	FIX::SenderCompID senderID = "CLIENT1";
	FIX::TargetCompID targetID = "SIMULADOR.ORDEM";
	FIX::Symbol symbol = symbolValue;
	FIX::ClOrdID clOrdID = std::to_string(ordID);
	FIX::Side side = '1';
	FIX::OrdType type = '2';
	FIX::Price price = priceValue;
	FIX::OrderQty quantity = quantityValue;
	FIX::TimeInForce time = '0';
	FIX::Text text = "Add order";
	FIX::HandlInst handlInst = '1';
	//	Order instance
	FIX42::NewOrderSingle order(clOrdID, handlInst, symbol, side, FIX::TransactTime(), type);
	order.set(price);
	order.set(quantity);
	order.set(time);
	FIX::Session::sendToTarget(order, senderID, targetID);
	runClient();
}

void Application::deleteOrder()
{
	cancelID += 2;
	FIX::SenderCompID senderID = "CLIENT1";
	FIX::TargetCompID targetID = "SIMULADOR.ORDEM";
	std::string idValue, symbolValue;
	std::cout << "Digite o id da ordem que voce quer remover:" << std::endl;
	std::cin >> idValue;
	std::cout << "Digite o simbolo da ordem que voce quer remover:" << std::endl;
	std::cin >> symbolValue;
	FIX42::OrderCancelRequest orderCancel (idValue,std::to_string(cancelID), symbolValue,'1', FIX::TransactTime());
	orderCancel.set(FIX::Text("Order cancel"));
	FIX::Session::sendToTarget(orderCancel, senderID, targetID);
	runClient();
}

void Application::listOrders()
{
}


