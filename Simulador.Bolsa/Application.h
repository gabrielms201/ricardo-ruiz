#pragma once
// includes 
#include <SocketAcceptor.h>
#include "OrderRepository.h"
#include "quickfix/MessageCracker.h"
#include "quickfix/Values.h"
#include "quickfix/Utility.h"
#include "quickfix/Mutex.h"
#include "quickfix/Application.h"
#include "quickfix/fix42/NewOrderSingle.h"
#include "quickfix/fix42/OrderCancelRequest.h"
#include "quickfix/fix42/MarketDataRequest.h"

class Application : public FIX::Application, FIX::MessageCracker
{
    // Overloads of application's virtual functionsimplementations
    void onCreate(const FIX::SessionID&);
    void onLogon(const FIX::SessionID&);
    void onLogout(const FIX::SessionID&);
    void toAdmin(FIX::Message&, const FIX::SessionID&);
    void toApp(FIX::Message&, const FIX::SessionID&);
    void fromAdmin(const FIX::Message&, const FIX::SessionID&);
    void fromApp(const FIX::Message&, const FIX::SessionID&);

    // Overloads of MessageCracker's virtual functions implementations
    void onMessage(const FIX42::NewOrderSingle&, const FIX::SessionID&);
    void onMessage(const FIX42::OrderCancelRequest&, const FIX::SessionID&);

    //Order features
    void sendOrder(const Order&);
    void refuseOrder(const Order&);
    void cancelOrder(const char side,const std::string& id);

public:
    OrderRepository _repoController;
    const OrderRepository& repo() { return _repoController; }
};