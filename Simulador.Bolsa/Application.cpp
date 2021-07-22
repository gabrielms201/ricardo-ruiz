#include "quickfix/Application.h"
#include "Application.h"

void Application::onCreate(const FIX::SessionID&)
{
}

void Application::onLogon(const FIX::SessionID&)
{
}

void Application::onLogout(const FIX::SessionID&)
{
}

void Application::toAdmin(FIX::Message&, const FIX::SessionID&)
{
}

void Application::toApp(FIX::Message&, const FIX::SessionID&)
{
}

void Application::fromAdmin(const FIX::Message&, const FIX::SessionID&)
{
}

void Application::fromApp(const FIX::Message&, const FIX::SessionID&)
{
}
