#include "pch.h"
#include "Driver.h"
#include "Address.h"

using namespace WinRTCompV1;
using namespace Platform;

Driver::Driver()
{
	person = new CPerson();
	addressCache = ref new WinRTCompV1::Address(&person->GetAddress());
}

Driver::Driver(String^ name, String^ surname)
{
	person = new CPerson(name->Data(), surname->Data());
	addressCache = ref new WinRTCompV1::Address(&person->GetAddress());
}

Driver::~Driver()
{
	delete person;
}

String^ Driver::Name::get()
{
	return ref new String(person->GetName().c_str());
}

void Driver::Name::set(String^ value)
{
	person->SetName(value->Data());
}

String^ Driver::Surname::get()
{
	return ref new String(person->GetSurname().c_str());
}

void Driver::Surname::set(String^ value)
{
	person->SetSurname(value->Data());
}

IAddress^ Driver::Address::get()
{
	return addressCache;
}

bool Driver::CanSave()
{
	return person->CanSave();
}

