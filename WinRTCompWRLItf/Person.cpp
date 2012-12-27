// Person.cpp
#include "pch.h"
#include "Person.h"

using namespace WinRTCompWRLItf;
using namespace Platform;

Person::Person()
{
}

String^ Person::Name::get()
{
	return ref new String(m_name.c_str());
}

void Person::Name::set(String^ value)
{
	m_name = value->Data();
}

String^ Person::Surname::get()
{
	return ref new String(m_surname.c_str());
}

void Person::Surname::set(String^ value)
{
	m_surname = value->Data();
}

bool Person::CanSave()
{
	return m_name.length() > 0 && m_surname.length() > 0;
}
