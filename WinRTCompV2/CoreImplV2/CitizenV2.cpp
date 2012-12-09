#include "pch.h"
#include "CitizenV2.h"

using namespace CoreImplV2;

CCitizen::CCitizen(void)
	: m_freeAddress(true)
{
	m_ptrAddress = new CAddress();
}

CCitizen::~CCitizen(void)
{
	FreeAddress();
}

CCitizen::CCitizen(std::wstring name, std::wstring surname) : 
	CPerson(name, surname), 
	m_freeAddress(true)
{
	m_ptrAddress = new CAddress();
}

CCitizen::CCitizen(std::wstring name, std::wstring surname, CAddress* address, bool freeAddress = true) : 
	CPerson(name, surname), 
	m_freeAddress(freeAddress)
{
	m_ptrAddress = address;
}

CCitizen::CCitizen(const CCitizen& other) : 
	CPerson(other), 
	m_freeAddress(true)
{
	this->m_ptrAddress = new CAddress(*other.m_ptrAddress);
}

CCitizen& CCitizen::operator=(const CCitizen& other)
{
	m_name = other.m_name;
	m_surname = other.m_surname;

	FreeAddress();
	m_freeAddress = true;
	m_ptrAddress = new CAddress(*other.m_ptrAddress);
	return *this;
}

void CCitizen::SetAddress(CAddress* value, bool freeAddress = true)
{
	FreeAddress();
	m_ptrAddress = value;
	m_freeAddress = freeAddress;
}

CAddress& CCitizen::GetAddress()
{
	return *m_ptrAddress;
}

bool CCitizen::CanSave()
{
	return CPerson::CanSave() && m_ptrAddress->CanSave();
}

void CCitizen::FreeAddress(void)
{
	if (m_freeAddress)
	{
		delete m_ptrAddress;
	}
}



