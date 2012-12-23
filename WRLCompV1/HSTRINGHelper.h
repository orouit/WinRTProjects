#pragma once

#include <wrl.h>
#include <string>

namespace Core
{
	class HSTRHelper
	{
	public:
		static const wchar_t* ToWChar(HSTRING value);

		static HRESULT FromWString(std::wstring valueIn, HSTRING* valueOut);
	};
}