#pragma once

#include <wrl.h>
#include <wrl\wrappers\corewrappers.h>
#include <wrl\client.h>

#define CanSaveMethod(className) \
	STDMETHODIMP className::CanSave(_Out_ boolean* value) { \
		return SaveableHelper::CanSave(value); }

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
	}
}


