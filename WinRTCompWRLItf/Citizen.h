#pragma once

#pragma warning( disable: 4251 )

#include <string>

using namespace Platform;
using namespace WRLCompV1;

namespace WinRTCompWRLItf
{
	/**
		Citizen implements the interfaces ICitizen, IPerson 
		and ISaveable defined in WRLCompV1
	 */
	public ref class Citizen sealed : ICitizen, IPerson, ISaveable
    {
	private:
    	std::wstring m_name;
		std::wstring m_surname;
		IAddress^ m_address;

	public:
        Citizen();

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

		virtual property IAddress^ Address {
			IAddress^ get();
			void set(IAddress^ value);
		}

		// ISaveable interface
		virtual bool CanSave();
    };
}