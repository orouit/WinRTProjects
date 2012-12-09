#pragma once

#include "CompRTV2.h"
#include "../CoreImplV2/AddressV2.h"

using namespace CoreImplV2;

namespace WinRTCompV2
{
	namespace WUXD = Windows::UI::Xaml::Data;

	[WUXD::Bindable]	
	public ref class Address sealed : IAddress
	{
	private:
		CAddress* m_ptrAddress;
		bool m_freeAddress;

		void FreeAddress(void);

	public:
		Address(void);
		Address(String^ street, String^ zip, String^ city);
		virtual ~Address();

	internal:
		Address(CAddress* address, bool freeAddress);
		CAddress& GetAddress() const;

	public:
		virtual property String^ Street {
			String^ get();
			void set(String^ value);
		}

		virtual property String^ ZipCode {
			String^ get();
			void set(String^ value);
		}

		virtual property String^ City {
			String^ get();
			void set(String^ value);
		}

		virtual bool CanSave();
	};
}

