#include "pch.h"
#include "AddressEx.h"

using namespace WinRTComp;

CAddress::CAddress()
{
}

CAddress::CAddress(String^ street)
{
	this->street = street;
}

void CAddress::SetStreet(String^ const value)
{
	this->street = value;
}

String^ CAddress::GetStreet()
{
	return this->street;
}

