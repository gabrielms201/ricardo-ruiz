#pragma comment(lib,"quickfix.lib")
#include <iostream>
#include "quickfix/Message.h"
#include "quickfix/FileStore.h"
#include "quickfix/FileLog.h"
#include "quickfix/SocketAcceptor.h"
#include "quickfix/Session.h"
#include "quickfix/SessionSettings.h"
#include "quickfix/Application.h"

int main() 
{
	std::cout << "Oi mundo";
	FIX::Message nome;
	int teste;
	std::cin >> teste;
	return 0;
}