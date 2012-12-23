#include "pch.h"

#include "WRLCompV1_h.h"
#include <wrl.h>
#include <wrl\wrappers\corewrappers.h>
#include <wrl\client.h>
#include <string>
#include "HSTRINGHelper.h"

using namespace Microsoft::WRL;
using namespace Microsoft::WRL::Wrappers;
using namespace Windows::Foundation;
using namespace Core;

namespace ABI
{
	namespace WRLCompV1
	{
		/**
			This class should provide a pre-implementation of the interface
			ISaveable for all components that need to implement it.

			But something is not exactly working like expected and I haven't managed to
			find out why. (Compilation issue)
		 */
		class SaveableHelper
		{
		public:
			/**
				Indirect implementation for ISaveable::CanSave(boolean *value);
			 */
			HRESULT CanSave(_Out_ boolean *value)
			{
				HRESULT hr = E_POINTER;

				if (value != nullptr)
				{
					*value = CanSaveImpl();
					hr = S_OK;
				}

				return hr;
			}

		protected:
			virtual boolean CanSaveImpl() = 0;
		};

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

		STDMETHODIMP PersonClass::get_Name(HSTRING* value)
		{
			return HSTRHelper::FromWString(m_name, value);
		}

		STDMETHODIMP PersonClass::put_Name(HSTRING value)
		{
			m_name = HSTRHelper::ToWChar(value);

			return S_OK;
		}

		STDMETHODIMP PersonClass::get_Surname(HSTRING* value)
		{
			return HSTRHelper::FromWString(m_surname, value);
		}

		STDMETHODIMP PersonClass::put_Surname(HSTRING value)
		{
			m_surname = HSTRHelper::ToWChar(value);

			return S_OK;
		}

		boolean PersonClass::CanSaveImpl()
		{
			return m_name.length() > 0 && m_surname.length() > 0;
		}

		STDMETHODIMP PersonClass::CanSave(_Out_ boolean* value)
		{
			return SaveableHelper::CanSave(value);
		}
	}
}