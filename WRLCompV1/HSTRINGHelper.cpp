#include "pch.h"

#include "HSTRINGHelper.h"
#include <wrl\wrappers\corewrappers.h>

using namespace Microsoft::WRL::Wrappers;

namespace Core
{
	const wchar_t* HSTRHelper::ToWChar(HSTRING value)
	{
		HString inValue;

		inValue.Set(value);
		return inValue.GetRawBuffer(nullptr);
	}

	HRESULT HSTRHelper::FromWString(std::wstring valueIn, HSTRING* valueOut)
	{
		HRESULT hRes = E_POINTER;
		HString tmpValue;

		if (valueOut != nullptr)
		{
			hRes = tmpValue.Set(valueIn.c_str());
			if (!FAILED(hRes))
			{
				// The string must be detached when returned by the function
				*valueOut = tmpValue.Detach();
				hRes = S_OK;
			}
		}

		return hRes;
	}
}
