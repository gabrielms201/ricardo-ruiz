#include "quickfix/FileStore.h"
#include "quickfix/FileLog.h"
#include "quickfix/SocketAcceptor.h"
#include "quickfix/Session.h"
#include "quickfix/SessionSettings.h"
#include "quickfix/Application.h"
#include "Application.h"

int main(int argc, char** argv)
{
	try
	{
		if (argc < 2) return 1;
		std::string fileName = argv[1];
		FIX::SessionSettings settings(fileName);
		Application application;
		FIX::FileStoreFactory storeFactory(settings);
		FIX::FileLogFactory logFactory(settings);
		FIX::SocketAcceptor acceptor
		(application, storeFactory, settings, logFactory);
		acceptor.start();
		int teste = 1;
		while (teste <= 10)
		{
			teste++;
		}
		acceptor.stop();
		return 0;
	}
	catch (FIX::ConfigError& e)
	{
		std::cout << e.what();
		return 1;
	}
}