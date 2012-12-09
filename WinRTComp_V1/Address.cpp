#include "pch.h"
#include "Address.h"

using namespace WinRTCompV1;

Address::Address(CAddress* address) : address(*address)
{
}

CAddress& Address::GetAddress() const
{
	return address; 
}

void Address::Street::set(String^ value)
{
	address.SetStreet(value->Data());
}

String^ Address::Street::get()
{
	return ref new String(address.GetStreet().c_str());
}

bool Address::CanSave()
{
	return address.CanSave();
}


