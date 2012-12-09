#include "pch.h"
#include "PersonRT2b.h"

/**
	@brief	This is the implementation class for the IPerson interface. This implementation is not using 
	any internal class. It is directly a COM component for the WinRT 
	String data are stored using std::wstring to demonstrate how to mix pure C++ types and WinRT projected 
	types.
*/
namespace WinRTCompV2
{
	Person2::Person2(void)
	{
	}

	Person2::Person2(String^ name, String^ surname) :
		m_name(name->Data()),
		m_surname(surname->Data())
	{
	}

	String^ Person2::Name::get()
	{
		return ref new String(m_name.c_str());
	}

	void Person2::Name::set(String^ value)
	{
		m_name = value->Data();
	}

	String^ Person2::Surname::get()
	{
		return ref new String(m_surname.c_str());
	}

	void Person2::Surname::set(String^ value)
	{
		m_surname = value->Data();
	}

	bool Person2::CanSave()
	{
		return m_name.length() > 0 && m_surname.length() > 0;
	}
}