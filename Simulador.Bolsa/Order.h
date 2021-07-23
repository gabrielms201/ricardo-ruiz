#pragma once
#include <string>
#include <iostream>

class Order
{
public:

	Order(const std::string& owner, const std::string& target, const std::string& symbol, const std::string& clientID , char side, char type, double price, double quantity)
	{
		_owner = owner;
		_target = target;
		_symbol = symbol;
		_clientID = clientID;
		_side = side;
		_type = type;
		_price = price;
		_quantity = quantity;
		_totalPrice = _quantity * _price;
	}

	// get properties
	const std::string& getOwner() { return _owner; }
	const std::string& getTarget() { return _target; }
	const std::string& getSymbol() { return _symbol; }
	const std::string& getClientID() { return _clientID; }
	const char getSide() { return _side; }
	const char getType() { return _type; }
	const double getPrice() { return _price; }
	const int getQuantity() { return _quantity; }
	const double getTotalPrice() { return _totalPrice; }

	// methods
	void executeOrder()
	{
		_totalPrice = _quantity * _price;
	}

private:
	std::string _owner; // sender 
	std::string _target;
	std::string _symbol;
	std::string _clientID;
	char _side;
	char _type;
	double _price;
	double _quantity;
	double _totalPrice;
};

