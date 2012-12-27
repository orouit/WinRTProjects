#pragma once

#include "HSTRINGHelper.h"

#define StringProperty(className, propertyName, memberName) \
		STDMETHODIMP className::get_##propertyName(HSTRING* value) { \
			return HSTRHelper::FromWString(memberName, value); } \
		STDMETHODIMP className::put_##propertyName(HSTRING value) { \
			memberName = HSTRHelper::ToWChar(value); return S_OK; }

			