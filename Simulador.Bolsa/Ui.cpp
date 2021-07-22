#pragma once
#include "Ui.h"

using namespace std;
void Ui::ShowUi()
{
	setlocale(LC_ALL, "");
	cout << "************************************************************" << endl;
	cout << "* Olá, bem vindo ao simulador de ordem de compra de ações! *" << endl;
	cout << "************************************************************" << endl;
	for (int i = 0; i < 20; i++)
	{
		cout << endl;
	}
}