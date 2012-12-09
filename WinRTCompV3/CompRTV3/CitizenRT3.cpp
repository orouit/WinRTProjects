#include "pch.h"
#include "CitizenRT3.h"

namespace WinRTCompV3
{
	Citizen::Citizen(void) :
		m_person(ref new Person()),
		m_iAddress(ref new WinRTCompV3::Address())
	{
	}

	Citizen::Citizen(String^ name, String^ surname) :
		m_person(ref new Person(name, surname)),
		m_iAddress(ref new WinRTCompV3::Address())
	{
	}

	Citizen::Citizen(String^ name, String^ surname, WinRTCompV3::Address^ address) :
		m_person(ref new Person(name, surname)),
		m_iAddress(address)
	{
	}

	String^ Citizen::Name::get()
	{
		return m_person->Name;
	}

	void Citizen::Name::set(String^ value)
	{
		m_person->Name = value;
	}

	String^ Citizen::Surname::get()
	{
		return m_person->Surname;
	}

	void Citizen::Surname::set(String^ value)
	{
		m_person->Surname = value;
	}

	WinRTCompV2::IAddress^ Citizen::Address::get()
	{
		return m_iAddress;
	}

	void Citizen::Address::set(IAddress^ value)
	{
		m_iAddress = value;
	}

	bool Citizen::CanSave()
	{
		return m_person->CanSave() && m_iAddress->CanSave();
	}
}