#include "pch.h"
#include "CoDriver.h"

using namespace WinRTCompV1;

CoDriver::CoDriver(void)
{
	person = new CPerson();
	addressCache = ref new WinRTCompV1::Address(&person->GetAddress());
}

CoDriver::CoDriver(String^ name, String^ surname)
{
	person = new CPerson(name->Data(), surname->Data());
	addressCache = ref new WinRTCompV1::Address(&person->GetAddress());
}

CoDriver::~CoDriver()
{
	delete person;
}

String^ CoDriver::Name::get()
{
	return ref new String(person->GetName().c_str());
}

void CoDriver::Name::set(String^ value)
{
	person->SetName(value->Data());
}

String^ CoDriver::Surname::get()
{
	return ref new String(person->GetSurname().c_str());
}

void CoDriver::Surname::set(String^ value)
{
	person->SetSurname(value->Data());
}

IAddress^ CoDriver::Address::get()
{
	return addressCache;
}

bool CoDriver::CanSave()
{
	return person->CanSave();
}




