#include "pch.h"
#include "AddressRT2b.h"

namespace WinRTCompV2
{
	Address2::Address2(void)
	{
	}

	Address2::Address2(String^ street, String^ zip, String^ city) :
		m_city(city->Data()),
		m_street(street->Data()),
		m_zipCode(zip->Data())
	{
	}

	void Address2::Street::set(String^ value)
	{
		m_street = value->Data();
	}

	String^ Address2::Street::get()
	{
		return ref new String(m_street.c_str());
	}

	String^ Address2::ZipCode::get()
	{
		return ref new String(m_zipCode.c_str());
	}

	void Address2::ZipCode::set(String^ value)
	{
		m_zipCode = value->Data();
	}

	String^ Address2::City::get()
	{
		return ref new String(m_city.c_str());
	}

	void Address2::City::set(String^ value)
	{
		m_city = value->Data();
	}

	bool Address2::CanSave()
	{
		return m_city.length() > 0 && m_street.length() > 0 && m_zipCode.length();
	}
}