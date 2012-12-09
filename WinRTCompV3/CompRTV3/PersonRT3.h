#pragma once

#pragma warning( disable: 4251 )

#include <string>

using namespace WinRTCompV2;
using namespace Platform;

namespace WinRTCompV3
{
	namespace WUXD = Windows::UI::Xaml::Data;

	/**
		@brief Implementation of the IPerson interface without a composition class. Person is a COM class that
		implements directly the IPerson interface as a WinRT cimponent.
	*/
	[WUXD::Bindable]	
	public ref class Person sealed : IPerson
	{
	private:
		std::wstring m_name;
		std::wstring m_surname;

	public:
		/**
			Parameter-less constructor. Builds an empty Person object
		*/
		Person(void);

		/**
			Creates a Person object with a name and surname

			@param name	Name of the person
			@param surname	Surname of the person
		*/
		Person(String^ name, String^ surname);

		/**
			Property for the name

			@value	Name for the person
			@return A String^ of the person Name
		*/
		virtual property String^ Name {
			String^ get();
			void set(String^ value);
		}

		/**
			Property for the name

			@value	Surname for the person
			@return A String^ of the person Surname
		*/
		virtual property String^ Surname {
			String^ get();
			void set(String^ value);
		}

		/**
			Checks if the Person object can be saved. A Person object can be saved if both
			Name and Surname are not empty

			@return  true if can be saved, false otherwise
		*/
		virtual bool CanSave();
	};
}
