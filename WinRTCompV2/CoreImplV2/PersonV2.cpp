#include "pch.h"
#include "PersonV2.h"

using namespace CoreImplV2;

CPerson::CPerson(void)
{
}

CPerson::CPerson(std::wstring name, std::wstring surname)
{
	Initialize(name, surname);
}

void CPerson::Initialize(std::wstring name, std::wstring surname)
{
	m_name = name;
	m_surname = surname;
}

std::wstring CPerson::GetName()
{
	return m_name;
}

void CPerson::SetName(const std::wstring value)
{
	m_name = value;
}

std::wstring CPerson::GetSurname()
{
	return m_surname;
}

void CPerson::SetSurname(const std::wstring value)
{
	m_surname = value;
}

bool CPerson::CanSave()
{
	return m_name.length() > 0 && m_surname.length() > 0;
}
