#pragma once
//includes
#include <string>
#include <iostream>

class Order
{
	friend std::ostream& operator<<(std::ostream&, Order&);
public:
	//constructor
	Order(const std::string& ordID, const std::string symbol, const double price, const double quantity, const double totalPrice, const double averagePrice)
	{
		_ordID = ordID;
		_symbol = symbol;
		_price = price;
		_quantity = quantity;
		_totalPrice = totalPrice;
		_averagePrice = averagePrice;
	}
	//get
	std::string getOrdID() { return _ordID; }
	std::string getSymbol() { return _symbol; }
	double getPrice() { return _price; }
	double getQuantity() { return _quantity; }
	double getTotalPrice() { return _totalPrice; }
	double getAveragePrice() { return _averagePrice; }

private:
	//attributes
	std::string _ordID;
	std::string _symbol;
	double _price;
	double _quantity;
	double _totalPrice;
	double _averagePrice;
};

inline std::ostream& operator<<(std::ostream& ostream, Order& order)
{
	return ostream
		<< "\nOrder ID: " << order.getOrdID() << std::endl
		<< "Order Symbol: " << order.getSymbol() << std::endl
		<< "Order Price: " << order.getPrice() << std::endl
		<< "Order Quantity: " << order.getQuantity() << std::endl
		<< "Order Total Price: " << order.getTotalPrice() << std::endl
		<< "Order Average Price: " << order.getAveragePrice() << std::endl;
}
