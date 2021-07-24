#pragma once
//includes
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
	}

	// get properties
	const std::string& getOwner() const { return _owner; }
	const std::string& getTarget() const { return _target; }
	const std::string& getSymbol() const { return _symbol; }
	const std::string& getClientID() const { return _clientID; }
	char getSide() const { return _side; }
	char getType() const { return _type; }
	double getPrice() const { return _price; }
	int getQuantity() const { return _quantity; }
	double getTotalPrice() const { return _totalPrice; }

	// methods
	void sendTotalPrice(double price, double quantity) 
	{
		_totalPrice = quantity * price;
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

