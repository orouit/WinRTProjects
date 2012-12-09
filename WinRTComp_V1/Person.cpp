#include "pch.h"
#include "Person.h"

using namespace ImplComp;

CPerson::CPerson(void)
{
}

CPerson::CPerson(std::wstring const name, std::wstring const surname)
{
	Initialize(name, surname);
}

CPerson::CPerson(std::wstring const name, std::wstring const surname, CAddress address)
{
	Initialize(name, surname);

	this->m_address = address; 
}

void CPerson::Initialize(std::wstring const name, std::wstring const surname)
{
	this->m_name = name;
	this->m_surname = surname;
}

std::wstring CPerson::GetName()
{
	return this->m_name;
}

void CPerson::SetName(std::wstring const value)
{
	this->m_name = value;
}

std::wstring CPerson::GetSurname()
{
	return this->m_surname;
}

void CPerson::SetSurname(std::wstring const value)
{
	this->m_surname = value;
}

CAddress& CPerson::GetAddress() 
{
	return m_address;
}

bool CPerson::CanSave()
{
	return m_name.length() > 0 && m_surname.length() > 0;
}

CAddress::CAddress()
{
}

CAddress::CAddress(std::wstring street)
{
	this->m_street = street;
}

void CAddress::SetStreet(std::wstring street)
{
	this->m_street = street;
}

std::wstring CAddress::GetStreet()
{
	return this->m_street;
}

bool CAddress::CanSave()
{
	return this->m_street.length() > 0;
}

