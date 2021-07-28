#include "Repo.h"

void Repo::addOrder(Order& order)
{
	_orderRepo.push_back(order);
}

void Repo::removeOrder(std::string id)
{
	Order order = findOrder(id);
	int position = findOrderIndex(order);
	_orderRepo.erase(_orderRepo.begin() + position-1);
}
void Repo::printRepo()
{
	int i = 0;
	std::vector<Order>::iterator iOrder;
	for (iOrder = _orderRepo.begin(); iOrder != _orderRepo.end(); ++iOrder)
	{
		Order order = _orderRepo[i];
		i++;
		std::cout << "\nOrdem n: " << "[ " << i << " ]";
		std::cout << order;
	}
}
int Repo::findOrderIndex(Order& order)
{
	std::vector<Order>::iterator i;
	int position = 1;
	for (i = _orderRepo.begin(); i != _orderRepo.end(); ++i)
	{
		if (i->getOrdID() == order.getOrdID())
		{
			return position;
		}
		position++;
	}
}
Order Repo::findOrder(std::string id)
{
	std::vector<Order>::iterator i;
	for (i = _orderRepo.begin(); i != _orderRepo.end(); ++i)
	{
		if (i->getOrdID() == id)
		{
			return (*i);
		}
	}
}

std::vector<Order> Repo::showOrders()
{
	return std::vector<Order>();
}

Order Repo::returnElement(int index)
{
	return _orderRepo[index];
}