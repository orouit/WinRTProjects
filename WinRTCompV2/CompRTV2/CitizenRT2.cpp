#include "pch.h"
#include <windows.h>
#include "AddressRT2.h"
#include "CitizenRT2.h"

using namespace WinRTCompV2;

Citizen::Citizen(CCitizen* citizen)
{
	m_ptrCitizen = citizen;
	ExtractAddress();
}

CCitizen& Citizen::GetCitizen(void) const
{
	return *m_ptrCitizen;
}

Citizen::Citizen(void)
{
	m_ptrCitizen = new CCitizen();
	ExtractAddress();
}

Citizen::Citizen(String^ name, String^ surname)
{
	m_ptrCitizen = new CCitizen(name->Data(), surname->Data());
	ExtractAddress();
}

Citizen::Citizen(String^ name, String^ surname, WinRTCompV2::Address^ address)
{
	m_address = address;	  
	m_ptrCitizen = new CCitizen(name->Data(), surname->Data(), &address->GetAddress(), false);
}

Citizen::~Citizen()
{
	delete m_ptrCitizen;
}

void Citizen::ExtractAddress(void)
{
	m_address = ref new WinRTCompV2::Address(&m_ptrCitizen->GetAddress(), false);
}

String^ Citizen::Name::get()
{
	return ref new String(m_ptrCitizen->GetName().c_str());
}

void Citizen::Name::set(String^ value)
{
	m_ptrCitizen->SetName(value->Data());
}

String^ Citizen::Surname::get()
{
	return ref new String(m_ptrCitizen->GetSurname().c_str());
}

void Citizen::Surname::set(String^ value)
{
	m_ptrCitizen->SetSurname(value->Data());
}

IAddress^ Citizen::Address::get()
{
	return m_address;
}

/**
	This set property is a HUGE problem with this type of implementation. 
*/
void Citizen::Address::set(IAddress^ value)
{
	WinRTCompV2::Address^ refAddress = nullptr;

	try
	{
		refAddress = (WinRTCompV2::Address^) value;
	}
	catch(InvalidCastException^ ex)
	{
		std::wstring msg = L"Address::set raised exception: ";
		msg.append(ex->Message->Data());
		OutputDebugString(msg.c_str());
	}

	if (refAddress == nullptr)
	{
		refAddress = ref new WinRTCompV2::Address(value->Street, value->ZipCode, value->City);
	}

	CAddress* ptrAddress = &refAddress->GetAddress();
	m_ptrCitizen->SetAddress(ptrAddress, false);
	m_address = refAddress;
}

bool Citizen::CanSave()
{
	return m_ptrCitizen->CanSave();
}