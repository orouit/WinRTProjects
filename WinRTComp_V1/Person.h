#pragma once
#include "Saveable.h"
#include <string>

using namespace Platform;

namespace ImplComp
{
	/**
		This class contains the address.

		CAddress is wrapped by the Address WinRT component and exposed as reference
	*/
	class CAddress : CSaveable
	{
	private:
		std::wstring m_street;

	public:
		CAddress(void);
		CAddress(std::wstring street);
		CAddress(const CAddress& other);

		void SetStreet(std::wstring street);
		std::wstring GetStreet();

		virtual bool CanSave();
	};

	/**
		This class represent a person with his address

		The CPerson is wrapped by the Driver or CoDriver WinRT component as a reference
	*/
	class CPerson : CSaveable
	{
	public:
		CPerson(void);
		CPerson(std::wstring const name, std::wstring const surname);
		CPerson(std::wstring const name, std::wstring const surname, CAddress address);

	private:
		CAddress m_address;
		std::wstring m_name;
		std::wstring m_surname;

		void Initialize(std::wstring const name, std::wstring const surname);

	public:
		void SetName(std::wstring const value);
		std::wstring GetName();

		void SetSurname(std::wstring const value);
		std::wstring GetSurname();

		CAddress& GetAddress();

		virtual bool CanSave();
	};
}
