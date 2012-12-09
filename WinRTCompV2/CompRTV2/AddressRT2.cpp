#include "pch.h"
#include "AddressRT2.h"

using namespace WinRTCompV2;

/**
	WARNING: The address pointer will be released when this object is deleted
 */
Address::Address(CAddress* address, bool freeAddress) :
	m_freeAddress(freeAddress)
{
	m_ptrAddress = address;
}

Address::Address(void) :
	m_freeAddress(true)
{
	m_ptrAddress = new CAddress();
}

Address::Address(String^ street, String^ zip, String^ city) :
	m_freeAddress(true)
{
	m_ptrAddress = new CAddress(street->Data(), zip->Data(), city->Data());
}

Address::~Address()
{
	FreeAddress();
}

CAddress& Address::GetAddress() const
{
	return *m_ptrAddress; 
}

void Address::Street::set(String^ value)
{
	m_ptrAddress->SetStreet(value->Data());
}

String^ Address::Street::get()
{
	return ref new String(m_ptrAddress->GetStreet().c_str());
}

String^ Address::ZipCode::get()
{
	return ref new String(m_ptrAddress->GetZipCode().c_str());
}

void Address::ZipCode::set(String^ value)
{
	m_ptrAddress->SetZipCode(value->Data());
}

String^ Address::City::get()
{
	return ref new String(m_ptrAddress->GetCity().c_str());
}

void Address::City::set(String^ value)
{
	m_ptrAddress->SetCity(value->Data());
}

bool Address::CanSave()
{
	return m_ptrAddress->CanSave();
}

void Address::FreeAddress(void)
{
	if (m_freeAddress)
	{
		delete m_ptrAddress;
	}
}


