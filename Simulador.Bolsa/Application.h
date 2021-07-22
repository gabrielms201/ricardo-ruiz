#pragma once
#include "quickfix/Application.h"
#include <SocketAcceptor.h>

class Application : public FIX::Application 
{
    void onCreate(const FIX::SessionID&);
    void onLogon(const FIX::SessionID&);
    void onLogout(const FIX::SessionID&);
    void toAdmin(FIX::Message&, const FIX::SessionID&);
    void toApp(FIX::Message&, const FIX::SessionID&);
    void fromAdmin(const FIX::Message&, const FIX::SessionID&);
    void fromApp(const FIX::Message&, const FIX::SessionID&);
};