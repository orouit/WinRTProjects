// Citizen.cpp
#include "pch.h"
#include "Citizen.h"
#include "Address.h"

using namespace WinRTCompWRLItf;
using namespace Platform;

Citizen::Citizen()
{
	m_address = ref new WinRTCompWRLItf::Address(); 
}

String^ Citizen::Name::get()
{
	return ref new String(m_name.c_str());
}

void Citizen::Name::set(String^ value)
{
	m_name = value->Data();
}

String^ Citizen::Surname::get()
{
	return ref new String(m_surname.c_str());
}

void Citizen::Surname::set(String^ value)
{
	m_surname = value->Data();
}

IAddress^ Citizen::Address::get()
{
	return m_address;
}

void Citizen::Address::set(IAddress^ value)
{
	m_address = value;
}

bool Citizen::CanSave()
{
	return 
		m_name.length() > 0 && 
		m_surname.length() > 0 && 
		((ISaveable^) m_address)->CanSave();
}
