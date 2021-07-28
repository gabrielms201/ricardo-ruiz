#include "quickfix/SocketInitiator.h"
#include "Application.h"
#include <string>
#include "quickfix/FileStore.h"
#include "quickfix/FileLog.h"
#include "quickfix/FileStore.h"
#include "quickfix/SocketInitiator.h"

#include "quickfix/ThreadedSSLSocketInitiator.h"
#include "quickfix/SSLSocketInitiator.h"
#include "quickfix/SessionSettings.h"
#include "quickfix/Log.h"
#include "Application.h"
#include <string>
#include <iostream>
#include <fstream>
int main(int argc, char** argv)
{
	try
	{
		if (argc != 2)
		{
			std::cout << "Por favor, utilizar o arquivo .bat no diretorio principal";
			return 0;
		}
		Application application;
		std::string fileName = argv[1];
		FIX::SessionSettings settings(fileName);
		FIX::FileStoreFactory storeFactory(settings);
		FIX::FileLogFactory logFactory(settings);
		FIX::SocketInitiator initiator(application, storeFactory, settings, logFactory);
		

		initiator.start();
		application.runClient();
		initiator.stop();
		return 0;
	}
	catch (FIX::ConfigError& e)
	{
		std::cout << e.what();
		return 1;
	}
}