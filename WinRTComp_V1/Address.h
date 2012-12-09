#pragma once

#include "IPerson.h"
#include "Person.h"

using namespace ImplComp;

namespace WinRTCompV1
{
	namespace WUXD = Windows::UI::Xaml::Data;

	[WUXD::Bindable]	
	public ref class Address sealed : IAddress
	{
	private:
		CAddress& address;

	internal:
		Address(CAddress* address);
		CAddress& GetAddress() const;

	public:
		virtual property String^ Street {
			String^ get();
			void set(String^ value);
		}

		virtual bool CanSave();
	};
}

