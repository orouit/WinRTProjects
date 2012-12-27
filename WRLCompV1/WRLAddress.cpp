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
		class AddressClass: public RuntimeClass<IAddress, ISaveable>, protected SaveableHelper
		{
			InspectableClass(L"WRLCompV1.AddressClass", BaseTrust)

		private:
			std::wstring m_street;
			std::wstring m_city;

		public:
			AddressClass()
			{
			}

			// IAddress
			IFACEMETHODIMP get_Street(_Out_ HSTRING* value);
			IFACEMETHODIMP put_Street(_In_ HSTRING value);
			IFACEMETHODIMP get_City(_Out_ HSTRING* value);
			IFACEMETHODIMP put_City(_In_ HSTRING value);

			// ISaveable
			IFACEMETHODIMP CanSave(_Out_ boolean* value);

		protected:
			virtual boolean CanSaveImpl();
		};

		ActivatableClass(AddressClass);

		// Implementation of AddressClass
		StringProperty(AddressClass, Street, m_street);
		StringProperty(AddressClass, City, m_city);

		// Implementation of ISaveable
		boolean AddressClass::CanSaveImpl()
		{
			return m_street.length() > 0 && m_city.length() > 0;
		}

		CanSaveMethod(AddressClass);
	}
}