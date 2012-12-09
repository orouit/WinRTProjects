#include "pch.h"
#include "AddressV2.h"

using namespace CoreImplV2;

CAddress::CAddress(void)
{
}

CAddress::CAddress(std::wstring street, std::wstring zipCode, std::wstring city)
{
	m_city = city;
	m_street = street;
	m_zipCode = zipCode;
}

std::wstring CAddress::GetStreet()
{
	return m_street;
}

void CAddress::SetStreet(const std::wstring value)
{
	m_street = value;
}

std::wstring CAddress::GetZipCode()
{
	return m_zipCode;
}

void CAddress::SetZipCode(const std::wstring value)
{
	m_zipCode = value;
}

std::wstring CAddress::GetCity()
{
	return m_city;
}

void CAddress::SetCity(const std::wstring value)
{
	m_city = value;
}

bool CAddress::CanSave()
{
	return m_street.length() > 0;
}
