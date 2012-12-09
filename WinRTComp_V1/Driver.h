#pragma once

#include "IPerson.h"
#include "Person.h"
#include "Address.h"

using namespace ImplComp;

namespace WinRTCompV1
{
	namespace WUXD = Windows::UI::Xaml::Data;

	[WUXD::Bindable]
	public ref class Driver sealed : IPerson
    {
	private:
		CPerson* person;
		IAddress^ addressCache;

    public:
        Driver();
		Driver(String^ name, String^ surname);
		virtual ~Driver();

	public:
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
		}

		virtual bool CanSave();
    };
}