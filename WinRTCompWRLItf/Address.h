#pragma once

#pragma warning( disable: 4251 )

#include <string>

using namespace Platform;
using namespace WRLCompV1;

namespace WinRTCompWRLItf
{
	/**
		Address implements the interfaces IAddress and ISaveable defined in WRLCompV1
	 */
	public ref class Address sealed : IAddress, ISaveable
    {
	private:
    	std::wstring m_street;
		std::wstring m_city;

	public:
        Address();

	public:
		// IPerson interface
		virtual property String^ Street {
			String^ get();
			void set(String^ value);
		}

		virtual property String^ City {
			String^ get();
			void set(String^ value);
		}

		// ISaveable interface
		virtual bool CanSave();
    };
}