#pragma once

#pragma warning( disable: 4251 )

#include "Saveable.h"
#include <string>

using namespace CoreImpl;

namespace CoreImplV2
{
	class CPerson : CSaveable
	{
	protected:
		std::wstring m_name;
		std::wstring m_surname;

	public:
		CPerson(void);
		CPerson(std::wstring name, std::wstring surname);

	public:
		std::wstring GetName();
		void SetName(const std::wstring value);

		std::wstring GetSurname();
		void SetSurname(const std::wstring value);

		virtual bool CanSave();

	private:
		void Initialize(std::wstring name, std::wstring surname);
	};
}

