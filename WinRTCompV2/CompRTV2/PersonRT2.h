#pragma once

#include "CompRTV2.h"
#include "../CoreImplV2/PersonV2.h"

using namespace CoreImplV2;

namespace WinRTCompV2
{
	namespace WUXD = Windows::UI::Xaml::Data;

	[WUXD::Bindable]	
	public ref class Person sealed : IPerson
	{
	private:
		CPerson* m_ptrPerson;

	internal:
		Person(CPerson* person);
		CPerson& GetPerson() const;

	public:
		Person(void);
		Person(String^ name, String^ surname);
		virtual ~Person();

		virtual property String^ Name {
			String^ get();
			void set(String^ value);
		}

		virtual property String^ Surname {
			String^ get();
			void set(String^ value);
		}

		virtual bool CanSave();
	};
}