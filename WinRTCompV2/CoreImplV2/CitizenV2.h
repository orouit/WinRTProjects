#pragma once

#include "PersonV2.h"
#include "AddressV2.h"

namespace CoreImplV2
{
	class CCitizen : public CPerson
	{
	private:
		CAddress* m_ptrAddress;
		bool m_freeAddress;

		void FreeAddress(void);

	public:
		CCitizen(void);
		CCitizen(std::wstring name, std::wstring surname);
		CCitizen(std::wstring name, std::wstring surname, CAddress* address, bool freeAddress);
		CCitizen(const CCitizen& other);
		~CCitizen(void);

		CCitizen & operator=(const CCitizen& other);

		void SetAddress(CAddress* value, bool freeAddress);
		CAddress& GetAddress();

		virtual bool CanSave();
	};
}

