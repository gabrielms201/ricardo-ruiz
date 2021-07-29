#include "Application.h"
#include <iostream>
#include "quickfix/MessageCracker.h"

// FIX Setup
void Application::onCreate(const FIX::SessionID&) {}

void Application::onLogon(const FIX::SessionID&) {}

void Application::onLogout(const FIX::SessionID&) {}

void Application::toAdmin(FIX::Message&, const FIX::SessionID&) {}

void Application::toApp(FIX::Message& message, const FIX::SessionID&) {}

void Application::fromAdmin(const FIX::Message&, const FIX::SessionID&) {}

void Application::fromApp(const FIX::Message& message, const FIX::SessionID& sessionID)
{
	crack(message, sessionID);
}
void Application::onMessage(const FIX42::ExecutionReport& message, const FIX::SessionID&)
{
	if (message.get(FIX::Text()) == "Execution report: a new order has been added") 
	{
		FIX::OrderID ordID;
		FIX::ClOrdID clOrdID;
		FIX::Symbol symbol;
		FIX::Price price;
		FIX::OrderQty quantity;
		FIX::CumQty totalPrice;
		FIX::AvgPx averagePrice;
		FIX::Side side;

		message.get(ordID);
		message.get(clOrdID);
		message.get(symbol);
		message.get(price);
		message.get(quantity);
		message.get(totalPrice);
		message.get(averagePrice);
		message.get(side);

		Order order(ordID, symbol, price, quantity, totalPrice, averagePrice, side);
		_repo.addOrder(order);
	}
}

void Application::onMessage(const FIX42::OrderCancelReject&, const FIX::SessionID&) {}

// Client methods
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
		<< "1-) Nova ordem\n"
		<< "2-) Cancelar ordem\n"
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
	char sideValue;
	// Input
	std::cout << "\nDigite a quantidade:";
	std::cin >> quantityValue;
	std::cout << "Digite o preco:";
	std::cin >> priceValue;
	std::cout << "Digite o simbolo:";
	std::cin >> symbolValue;
	std::cout << "Digite o lado da ordem: (1 para compra / 2 para venda): ";
	std::cin >> sideValue;
	//	Variables
	FIX::SenderCompID senderID = "CLIENT1";
	FIX::TargetCompID targetID = "SIMULADOR.ORDEM";
	FIX::Symbol symbol = symbolValue;
	FIX::ClOrdID clOrdID = std::to_string(ordID);
	FIX::Side side = sideValue;
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
	std::string sideText;
	if (side == '1') sideText = "Compra"; else sideText = "Venda";
	std::cout << "\nOrdem criada:\n> id: " << ordID << "\n> preco: " << price << "\n> quantidade: " << quantity << "\n> simbolo: " << symbol << "\n> lado: " << sideText << std::endl;
	ordID += 1;
	runClient();
}

void Application::deleteOrder()
{
	std::string idValue, symbolValue;
	char side;
	std::cout << "Digite o id da ordem que voce quer remover:";
	std::cin >> idValue;
	std::cout << "Digite o simbolo da ordem que voce quer remover:";
	std::cin >> symbolValue;
	FIX::SenderCompID senderID = "CLIENT1";
	FIX::TargetCompID targetID = "SIMULADOR.ORDEM";
	std::cout << "Digite o lado da ordem: (1 para compra / 2 para venda): ";
	std::cin >> side;
	FIX42::OrderCancelRequest orderCancel(FIX::OrigClOrdID(idValue), FIX::ClOrdID(std::to_string(cancelOrdID)), FIX::Symbol(symbolValue), FIX::Side(side), FIX::TransactTime());
	orderCancel.set(FIX::Text("Order Cancel Request"));
	FIX::Session::sendToTarget(orderCancel, senderID, targetID);
	std::cout << "Ordem cancelada!\nId da ordem de cancelamento gerada: " << cancelOrdID;
	_repo.removeOrder(idValue);
	cancelOrdID += 1;
	runClient();
}

void Application::listOrders() 
{
	_repo.printRepo();
	runClient();
}
