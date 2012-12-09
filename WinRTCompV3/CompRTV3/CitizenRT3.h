#pragma once

#include "PersonRT3.h"
#include "AddressRT3.h"

using namespace WinRTCompV2;

namespace WinRTCompV3
{
	namespace WUXD = Windows::UI::Xaml::Data;

	[WUXD::Bindable]	
	public ref class Citizen sealed : ICitizen
	{
	private:
		IAddress^ m_iAddress;
		Person^ m_person;

	public:
		Citizen(void);
		Citizen(String^ name, String^ surname);
		Citizen(String^ name, String^ surname, Address^ address);

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

		virtual bool CanSave();
	};
}
