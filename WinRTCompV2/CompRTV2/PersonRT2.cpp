#include "pch.h"
#include "PersonRT2.h"

using namespace CoreImplV2;
using namespace WinRTCompV2;

Person::Person(CPerson* person)
{
	m_ptrPerson = person;
}

Person::Person(void)
{
	m_ptrPerson = new CPerson();
}

Person::Person(String^ name, String^ surname)
{
	m_ptrPerson = new CPerson(name->Data(), surname->Data());
}

Person::~Person()
{
	delete m_ptrPerson;
}

CPerson& Person::GetPerson() const
{
	return *m_ptrPerson;
}

String^ Person::Name::get()
{
	return ref new String(m_ptrPerson->GetName().c_str());
}

void Person::Name::set(String^ value)
{
	m_ptrPerson->SetName(value->Data());
}

String^ Person::Surname::get()
{
	return ref new String(m_ptrPerson->GetSurname().c_str());
}

void Person::Surname::set(String^ value)
{
	m_ptrPerson->SetSurname(value->Data());
}

bool Person::CanSave()
{
	return m_ptrPerson->CanSave();
}
