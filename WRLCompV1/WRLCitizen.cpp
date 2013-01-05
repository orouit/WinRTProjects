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
			WRL component class for the ICitizen interface. Also implements ISaveable and IPerson as 
			seperate interfaces
		 */
class CitizenClass: public RuntimeClass<ICitizen, IPerson, ISaveable>, protected SaveableHelper
{
	InspectableClass(L"WRLCompV1.CitizenClass", BaseTrust)

private:
	std::wstring m_name;
	std::wstring m_surname;
	ABI::WRLCompV1::IAddress* m_pAddress;

public:
	CitizenClass()
	{
		m_pAddress = nullptr;
		ComPtr<ABI::WRLCompV1::IAddress> pAddress;
		HStringReference activableClassId(L"WRLCompV1.AddressClass");
		HRESULT hr = ActivateInstance<ComPtr<ABI::WRLCompV1::IAddress>>(activableClassId.Get(), &pAddress);

		// Detach the pointer from the ComPtr class and manually call AddRef()
		m_pAddress = pAddress.Detach();
		m_pAddress->AddRef();
	}

	~CitizenClass()
	{
		// When the class is destroyed, release the reference of IAddress
		if (m_pAddress != nullptr)
		{
			m_pAddress->Release();
		}
	}

public:
	// IPerson, ICitizen
	IFACEMETHODIMP get_Name(_Out_ HSTRING* value);
	IFACEMETHODIMP put_Name(_In_ HSTRING value);
	IFACEMETHODIMP get_Surname(_Out_ HSTRING* value);
	IFACEMETHODIMP put_Surname(_In_ HSTRING value);

	// ICitizen
	IFACEMETHODIMP get_Address(_Out_ ABI::WRLCompV1::IAddress** value);
	IFACEMETHODIMP put_Address(_In_ ABI::WRLCompV1::IAddress* value);

	// ISaveable
	IFACEMETHODIMP CanSave(_Out_ boolean* value);

protected:
	virtual boolean CanSaveImpl();
};

ActivatableClass(CitizenClass);

// Implementation of IPerson, ICitizen
StringProperty(CitizenClass, Name, m_name);
StringProperty(CitizenClass, Surname, m_surname);

// Implementation of ICitizen
STDMETHODIMP CitizenClass::get_Address(ABI::WRLCompV1::IAddress** value)
{
	HRESULT hr = E_POINTER;

	if (value != nullptr)
	{
		*value = m_pAddress;
		hr = S_OK;
	}

	return hr;
}

STDMETHODIMP CitizenClass::put_Address(ABI::WRLCompV1::IAddress* value)
{
	HRESULT hr = E_POINTER;

	if (value != nullptr)
	{
		// Release the previouslu used IAddress
		if (m_pAddress != nullptr)
		{
			m_pAddress->Release();
		}

		// Set the given one and increase the reference count
		m_pAddress = value;
		m_pAddress->AddRef();
		hr = S_OK;
	}

	return hr;
}

// Implementation of ISaveable
boolean CitizenClass::CanSaveImpl()
{
	boolean canSave = true;
	ComPtr<ABI::WRLCompV1::ISaveable> pSaveable;
	ComPtr<ABI::WRLCompV1::IAddress> pAddress = m_pAddress;
	HRESULT hr = pAddress.As(&pSaveable);
	if (SUCCEEDED(hr))
	{
		hr = pSaveable->CanSave(&canSave);
	}

	return m_name.length() > 0 && m_surname.length() > 0 && canSave;
}

CanSaveMethod(CitizenClass);
}
}