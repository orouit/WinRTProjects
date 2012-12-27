#pragma once

#pragma warning( disable: 4251 )

#include <string>

using namespace Platform;
using namespace WRLCompV1;

namespace WinRTCompWRLItf
{
	/**
		Person implements the interfaces IPerson and ISaveable defined in WRLCompV1
	 */
	public ref class Person sealed : IPerson, ISaveable
    {
	private:
    	std::wstring m_name;
		std::wstring m_surname;

	public:
        Person();

	public:
		// IPerson interface
		virtual property String^ Name {
			String^ get();
			void set(String^ value);
		}

		virtual property String^ Surname {
			String^ get();
			void set(String^ value);
		}

		// ISaveable interface
		virtual bool CanSave();
    };
}