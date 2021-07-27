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
		//if (argc != 2)
		//{
			//std::cout << "Por favor, utilizar o arquivo .bat no diretorio principal";
			//return 0;
		//}
		std::string fileName = "C:\\Users\\Ricar\\temp\\ricardo-ruiz\\Simulador.Bolsa\\Simulador.Bolsa.cfg";//argv[1];
		Application application;
		FIX::SessionSettings settings(fileName);
		FIX::FileStoreFactory storeFactory(settings);
		FIX::ScreenLogFactory logFactory(settings);
		FIX::SocketAcceptor acceptor(application, storeFactory, settings, logFactory);

		acceptor.start();
		while (true)
		{

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