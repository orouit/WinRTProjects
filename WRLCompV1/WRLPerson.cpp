#include "pch.h"

#include "WRLCompV1_h.h"
#include "SaveableHelper.h"

#include <wrl.h>
#include <wrl\wrappers\corewrappers.h>
#include <wrl\client.h>
#include <string>
#include "HSTRINGHelper.h"
#include "..\include\coredef.h";

using namespace Microsoft::WRL;
using namespace Microsoft::WRL::Wrappers;
using namespace Windows::Foundation;
using namespace Core;

namespace ABI
{
	namespace WRLCompV1
	{
		/**
			WRL component class for the IPerson interface. Also implements ISaveable as 
			a seperate interface
		 */
		class PersonClass: public RuntimeClass<IPerson, ISaveable>, protected SaveableHelper
		{
			InspectableClass(L"WRLCompV1.PersonClass", BaseTrust)

		private:
			std::wstring m_name;
			std::wstring m_surname;

		public:
			PersonClass()
			{
			}

		public:
			// IPerson
			IFACEMETHODIMP get_Name(_Out_ HSTRING* value);
			IFACEMETHODIMP put_Name(_In_ HSTRING value);
			IFACEMETHODIMP get_Surname(_Out_ HSTRING* value);
			IFACEMETHODIMP put_Surname(_In_ HSTRING value);

			// ISaveable
			IFACEMETHODIMP CanSave(_Out_ boolean* value);

		protected:
			virtual boolean CanSaveImpl();
		};

		ActivatableClass(PersonClass);

		// Implementation of IPerson
		StringProperty(PersonClass, Name, m_name);
		StringProperty(PersonClass, Surname, m_surname);

		// Implementation of ISaveable
		boolean PersonClass::CanSaveImpl()
		{
			return m_name.length() > 0 && m_surname.length() > 0;
		}

		CanSaveMethod(PersonClass);
	}
}