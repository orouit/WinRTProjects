#include "pch.h"
#include "AddressRT3.h"

namespace WinRTCompV3
{
	Address::Address(void)
	{
	}

	Address::Address(String^ street, String^ zip, String^ city) :
		m_city(city->Data()),
		m_street(street->Data()),
		m_zipCode(zip->Data())
	{
	}

	void Address::Street::set(String^ value)
	{
		m_street = value->Data();
	}

	String^ Address::Street::get()
	{
		return ref new String(m_street.c_str());
	}

	String^ Address::ZipCode::get()
	{
		return ref new String(m_zipCode.c_str());
	}

	void Address::ZipCode::set(String^ value)
	{
		m_zipCode = value->Data();
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
		return m_city.length() > 0 && m_street.length() > 0 && m_zipCode.length();
	}
}