#pragma once
//includes
#include <map>
#include <queue>
#include <string>
#include "Order.h"
#include <functional>

class OrderRepository
{
public:
	//Order operations
	bool addOrder(const Order& order);				// add order
	bool deleteOrder(const Order& order);			// delete order	
	bool matchOrder(std::queue <Order>&);			// match order algorithm
	Order& findOrder(char side, std::string id);	// find order by id
private:
	//Order repo for Bidding and Offer (ask)
	typedef std::multimap <double, Order, std::greater <double> > BidOrder;	// Bid repo
	typedef std::multimap <double, Order, std::less<double> > OfferOrder;	// Order/Ask repo

	void matchOrder(Order& bid, Order& ask);		// match order algorithm	

	BidOrder _bidOrder;
	OfferOrder _offerOrder;
	std::queue <Order> _pendingOrders;
};