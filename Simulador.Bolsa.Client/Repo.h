#pragma once
//includes
#include <iostream>
#include <vector>
#include "Order.h"
class Repo
{
public:
	void addOrder(Order& order);
	void removeOrder(std::string id);
	void printRepo();
	Order findOrder(std::string id);
	Order returnElement(int index);
	int findOrderIndex(Order& order);
	std::vector<Order> _orderRepo;
	std::vector<Order> showOrders();
private:

};