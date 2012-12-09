#pragma once

#include "CompRTV2.h"
#include "../CoreImplV2/CitizenV2.h"

using namespace CoreImplV2;

namespace WinRTCompV2
{
	namespace WUXD = Windows::UI::Xaml::Data;

	[WUXD::Bindable]	
	public ref class Citizen sealed : ICitizen
	{
	private:
		CCitizen* m_ptrCitizen;
		IAddress^ m_address;

		void ExtractAddress(void);

	internal:
		/**
			Constructs a Citizen WinRT components from a C++ CCitizen object

			@param	citizen Pointer to a CCitizen instance
		*/
		Citizen(CCitizen* citizen);

		/**
			Gets the reference to the underlying CCitizen object 

			@return A reference to the CCitizen
		*/
		CCitizen& GetCitizen(void) const;

	public:
		Citizen(void);
		Citizen(String^ name, String^ surname);
		Citizen(String^ name, String^ surname, Address^ address);
		virtual ~Citizen();

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