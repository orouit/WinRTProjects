#include "pch.h"
#include "CitizenRT2b.h"

namespace WinRTCompV2
{
	Citizen2::Citizen2(void) :
		m_person(ref new Person2()),
		m_iAddress(ref new Address2())
	{
	}

	Citizen2::Citizen2(String^ name, String^ surname) :
		m_person(ref new Person2(name, surname)),
		m_iAddress(ref new Address2())
	{
	}

	Citizen2::Citizen2(String^ name, String^ surname, Address2^ address) :
		m_person(ref new Person2(name, surname)),
		m_iAddress(address)
	{
	}

	String^ Citizen2::Name::get()
	{
		return m_person->Name;
	}

	void Citizen2::Name::set(String^ value)
	{
		m_person->Name = value;
	}

	String^ Citizen2::Surname::get()
	{
		return m_person->Surname;
	}

	void Citizen2::Surname::set(String^ value)
	{
		m_person->Surname = value;
	}

	IAddress^ Citizen2::Address::get()
	{
		return m_iAddress;
	}

	void Citizen2::Address::set(IAddress^ value)
	{
		m_iAddress = value;
	}

	bool Citizen2::CanSave()
	{
		return m_person->CanSave() && m_iAddress->CanSave();
	}
}