#pragma once
// includes
#include <iostream>
#include <SocketInitiator.h>
#include <MessageCracker.h>
#include "quickfix/Session.h"
#include "quickfix/Application.h"
#include "quickfix/Application.h"
#include "quickfix/Session.h"
#include "quickfix/config-all.h"
#include "quickfix/Application.h"
#include "quickfix/Values.h"
#include "quickfix/Utility.h"
#include "quickfix/Mutex.h"
#include "quickfix/fix42/NewOrderSingle.h"
#include "quickfix/fix42/ExecutionReport.h"
#include "quickfix/fix42/OrderCancelRequest.h"
#include "quickfix/fix42/OrderCancelReject.h"

class Application : public FIX::Application, public FIX::MessageCracker
{
    // Overloads of application's virtual functionsimplementations
    void onCreate(const FIX::SessionID&);
    void onLogon(const FIX::SessionID&);
    void onLogout(const FIX::SessionID&);
    void toAdmin(FIX::Message&, const FIX::SessionID&);
    void toApp(FIX::Message&, const FIX::SessionID&);
    void fromAdmin(const FIX::Message&, const FIX::SessionID&);
    void fromApp(const FIX::Message&, const FIX::SessionID&);

    void onMessage(const FIX42::ExecutionReport&, const FIX::SessionID&);
    void onMessage(const FIX42::OrderCancelReject&, const FIX::SessionID& );


    // Client Methods
    char mainMenu();
    void addOrder();
    void deleteOrder();
    void listOrders();

    // Public
public:
    void runClient();
    int ordID = 1;
};