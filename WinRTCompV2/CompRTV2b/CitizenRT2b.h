#pragma once

#include "PersonRT2b.h"
#include "AddressRT2b.h"

namespace WinRTCompV2
{
	namespace WUXD = Windows::UI::Xaml::Data;

	[WUXD::Bindable]	
	public ref class Citizen2 sealed : ICitizen
	{
	private:
		IAddress^ m_iAddress;
		Person2^ m_person;

	public:
		Citizen2(void);
		Citizen2(String^ name, String^ surname);
		Citizen2(String^ name, String^ surname, Address2^ address);

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
