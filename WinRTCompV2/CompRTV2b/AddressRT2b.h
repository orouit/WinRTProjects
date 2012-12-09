#pragma once

#pragma warning( disable: 4251 )

#include "../CompRTV2/CompRTV2.h"
#include <string>

using namespace Platform;

namespace WinRTCompV2
{
	namespace WUXD = Windows::UI::Xaml::Data;

	[WUXD::Bindable]	
	public ref class Address2 sealed : IAddress
	{
	private:
		std::wstring m_street;
		std::wstring m_zipCode;
		std::wstring m_city;

	public:
		Address2(void);
		Address2(String^ street, String^ zip, String^ city);

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