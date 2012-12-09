#pragma once

#pragma warning( disable: 4251 )

#include <string>
#include "Saveable.h"

using namespace CoreImpl;

namespace CoreImplV2
{
	class CAddress : CSaveable
	{
	private:
		std::wstring m_street;
		std::wstring m_zipCode;
		std::wstring m_city;

	public:
		CAddress(void);
		CAddress(std::wstring street, std::wstring zipCode, std::wstring city);

	public:
		std::wstring GetStreet();
		void SetStreet(const std::wstring value);

		std::wstring GetZipCode();
		void SetZipCode(const std::wstring value);

		std::wstring GetCity();
		void SetCity(const std::wstring value);

		virtual bool CanSave();
	};
}

