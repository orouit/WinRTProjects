// Address.cpp
#include "pch.h"
#include "Address.h"

using namespace WinRTCompWRLItf;
using namespace Platform;

Address::Address()
{
}

String^ Address::Street::get()
{
	return ref new String(m_street.c_str());
}

void Address::Street::set(String^ value)
{
	m_street = value->Data();
}

String^ Address::City::get()
{
	return ref new String(m_city.c_str());
}

void Address::City::set(String^ value)
{
	m_city = value->Data();
}

bool Address::CanSave()
{
	return m_street.length() > 0 && m_street.length() > 0;
}
