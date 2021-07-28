#include "OrderRepository.h"
#include "Order.h"

// Add Order implementation
bool OrderRepository::addOrder(const Order& order)
{
	if (order.getSide() == '1')
	{
		_bidOrder.insert(BidOrder::value_type(order.getPrice(), order));
		return true;
	}
	else if (order.getSide() == '2')
	{
		_offerOrder.insert(OfferOrder::value_type(order.getPrice(), order));
		return true;
	}
	else return false;
}
// Delete Order implementation
bool OrderRepository::deleteOrder(const Order& order)
{
	if (order.getSide() == '1')
	{
		BidOrder::iterator i;
		std::string id = order.getClientID(); // had to instantiate it before to save some performance 
		for (i = _bidOrder.begin(); i != _bidOrder.end(); i++) // this iteration tries to find the given order in the available multimap 
		{
			if ((*i).second.getClientID() == id)
			{
				_bidOrder.erase(i);
				return true;
			}
			else return false;
		}
	}
	else if (order.getSide() == '2')
	{
		OfferOrder::iterator i;
		std::string id = order.getClientID(); // had to instantiate it before to save some performance 
		for (i = _offerOrder.begin(); i != _offerOrder.end(); i++) // this iteration tries to find the given order in the available multimap 
		{
			if ((*i).second.getClientID() == id)
			{
				_offerOrder.erase(i);
			}
			else return false;
		}
	}
	else return false;
}
// Match Order implementation
bool OrderRepository::matchOrder(std::queue<Order>& orders)
{
	while (true)
	{
		if (!_bidOrder.size() || !_offerOrder.size())
			return orders.size() != 0;
		BidOrder::iterator iBid = _bidOrder.begin();
		OfferOrder::iterator iOffer = _offerOrder.begin();
		if (iBid->second.getPrice() >= iOffer->second.getPrice())
		{
			Order & bid = (*iBid).second;
			Order& offer = (*iOffer).second;
			matchOrder(bid, offer);
			orders.push(bid);
			orders.push(offer);
		}
		else
			return orders.size() != 0;
	}
}
void OrderRepository::matchOrder(Order& bid, Order& offer)
{
	double price = offer.getPrice();
	double quantity = 0;

	if (bid.getQuantity() > offer.getQuantity())
		quantity = offer.getQuantity();
	else
		quantity = bid.getQuantity();

	bid.getTotalPrice();
	offer.getTotalPrice();
}
// Find Order by id implementation
Order& OrderRepository::findOrder(char side, std::string id)
{
	if (side == '1') // char 1 represents buying side
	{
		BidOrder::iterator i;
		for (i = _bidOrder.begin(); i != _bidOrder.end(); ++i)
		{
			if ((*i).second.getClientID() == id)
			{
				return (*i).second;
			}
			
		}
	}
	else if (side == '2') // char 2 represents selling side
	{
		OfferOrder::iterator i;
		for (i = _offerOrder.begin(); i != _offerOrder.end(); ++i)
		{
			if ((*i).second.getClientID() == id)
			{
				return (*i).second;
			}
		}
	}
	else throw new std::exception("Wasn't possible to find an order with the given id");
}
