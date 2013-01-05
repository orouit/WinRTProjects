#include "pch.h"
#include "CppUnitTest.h"
#include "..\WRLCompV1\WRLCompV1_h.h"
#include <Windows.Foundation.h>
#include <wrl\wrappers\corewrappers.h>
#include <wrl\client.h>
#include <stdio.h>
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace ABI::Windows::Foundation;
using namespace Microsoft::WRL;
using namespace Microsoft::WRL::Wrappers;

#define TEXT_STR1		L"Owen Farm"
#define TEXT_CTY1		L"Mos Eisly"
#define TEXT_STR2		L"Senate Apartment Complex"
#define TEXT_CTY2		L"Coruscant"
#define TEXT_NAME1		L"Luke"
#define TEXT_SURNAME1	L"Skywlaker"
#define TEXT_NAME2		L"Darth"
#define TEXT_SURNAME2	L"Vador"
#define TEXT_NAME3		L"Obi-Wan"
#define TEXT_SURNAME3	L"Kenobi"

#define TestPutProperty(instance, propertyName, hstring) \
	Assert::IsTrue(SUCCEEDED(instance->put_##propertyName(hstring.Get()))); 

#define TestGetProperty(instance, propertyName, hstring) \
	Assert::IsTrue(SUCCEEDED(instance->get_##propertyName(&hstring))); 


namespace UnitTestWRLCompCpp
{
    TEST_CLASS(UnitTestCompWRL)
    {
    public:
		/**
			Test the IPerson and ISaveable interfaces implemented by a WRL component
		 */
        TEST_METHOD(TestCompV1WithWRL)
        {
			// Activate the WRLCompV1.Person that implements ABI::WRLCompV1::IPerson
			ComPtr<ABI::WRLCompV1::IPerson> pIPersonWrl;

			CreateIPerson(L"WRLCompV1.PersonClass", &pIPersonWrl);

			TestIPerson(pIPersonWrl, TEXT_NAME1, TEXT_SURNAME1);

			TestISaveable(pIPersonWrl);
        }

		/**
			Test the IPerson and ISaveable interfaces implemented by a C++/CX component
		 */
        TEST_METHOD(TestCompV1ItfWinRTCompCpp)
        {
			// Activate the WinRTCompWRLItf.Person that implements ABI::WRLCompV1::IPerson
			ComPtr<ABI::WRLCompV1::IPerson> pIPersonWrl;
			CreateIPerson(L"WinRTCompWRLItf.Person", &pIPersonWrl);

			TestIPerson(pIPersonWrl, TEXT_NAME2, TEXT_SURNAME2);

			TestISaveable(pIPersonWrl);
		}

		/**
			Test the IPerson and ISaveable interfaces implemented by a C# component
		 */
        TEST_METHOD(TestCompV1ItfWinRTCompCsharp)
        {
			// Activate the WinRTCompCsharpWRLItf.Person that implements ABI::WRLCompV1::IPerson
			ComPtr<ABI::WRLCompV1::IPerson> pIPersonWrl;

			CreateIPerson(L"WinRTCompCsharpWRLItf.Person", &pIPersonWrl);

			TestIPerson(pIPersonWrl, TEXT_NAME3, TEXT_SURNAME3);

			TestISaveable(pIPersonWrl);
		}

		TEST_METHOD(TestWRLCiticen)
		{
			ComPtr<ABI::WRLCompV1::ICitizen> pICitizen;
			CreateComponent(L"WRLCompV1.CitizenClass", &pICitizen);

			// Get the address object
			ComPtr<ABI::WRLCompV1::IAddress> pIAddress;

			HRESULT hr = pICitizen->get_Address(&pIAddress);

			HString street;
			HString city;
			street.Set(TEXT_STR1);
			city.Set(TEXT_CTY1);

			// Set the Street and the City
			TestPutProperty(pIAddress, Street, street);
			TestPutProperty(pIAddress, City, city);
		}

		/**
			Mixing C# and C++/CX implementation
		 */
		TEST_METHOD(TestMixCsharpWithCppCX)
		{
			ComPtr<ABI::WRLCompV1::ICitizen> pICitizen;
			ComPtr<ABI::WRLCompV1::IAddress> pIAddress;

			// Create the ICitizen and the IAddress instances
			CreateComponent(L"WinRTCompCsharpWRLItf.Citizen", &pICitizen);
			CreateComponent(L"WinRTCompWRLItf.Address", &pIAddress);
			
			TestMixCitizenAddress(pICitizen, 
				TEXT_NAME1, 
				TEXT_SURNAME1, 
				pIAddress,
				TEXT_STR1, 
				TEXT_CTY1,
				TEXT_STR2,
				TEXT_CTY2);
		}

		TEST_METHOD(TestMixWRLWithCppCX)
		{
			ComPtr<ABI::WRLCompV1::ICitizen> pICitizen;
			ComPtr<ABI::WRLCompV1::IAddress> pIAddress;

			// Create the ICitizen and the IAddress instances
			CreateComponent(L"WRLCompV1.CitizenClass", &pICitizen);
			CreateComponent(L"WinRTCompWRLItf.Address", &pIAddress);
			//CreateComponent(L"WRLCompV1.AddressClass", &pIAddress);
			
			TestMixCitizenAddress(pICitizen, 
				TEXT_NAME2, 
				TEXT_SURNAME2, 
				pIAddress,
				TEXT_STR1, 
				TEXT_CTY1,
				TEXT_STR2,
				TEXT_CTY2);
		}

		TEST_METHOD(TestMixWRLWithCsharp)
		{
			ComPtr<ABI::WRLCompV1::ICitizen> pICitizen;
			ComPtr<ABI::WRLCompV1::IAddress> pIAddress;

			// Create the ICitizen and the IAddress instances
			CreateComponent(L"WRLCompV1.CitizenClass", &pICitizen);
			CreateComponent(L"WinRTCompCsharpWRLItf.Address", &pIAddress);
			
			TestMixCitizenAddress(pICitizen, 
				TEXT_NAME3, 
				TEXT_SURNAME3, 
				pIAddress,
				TEXT_STR1, 
				TEXT_CTY1,
				TEXT_STR2,
				TEXT_CTY2);
		}

	private:
		template<typename T>
		void CreateComponent(const wchar_t* activableClassId, ::Microsoft::WRL::Details::ComPtrRef<ComPtr<T>> pInstance)
		{
			HStringReference runtimeClass(activableClassId);

			HRESULT hr = Windows::Foundation::ActivateInstance< ComPtr<T>>( runtimeClass.Get(), pInstance );
			Assert::IsTrue(SUCCEEDED(hr));
		}

		void CreateIPerson(const wchar_t* activableClassId, ::Microsoft::WRL::Details::ComPtrRef<ComPtr<ABI::WRLCompV1::IPerson>> pIPerson)
		{
			HStringReference runtimeClassPerson(activableClassId);

			HRESULT hr = Windows::Foundation::ActivateInstance< ComPtr<ABI::WRLCompV1::IPerson>>( runtimeClassPerson.Get(), pIPerson );
			Assert::IsTrue(SUCCEEDED(hr));
		}

void TestMixCitizenAddress(ComPtr<ABI::WRLCompV1::ICitizen> pICitizen, 
	const wchar_t* wsName,
	const wchar_t* wsSurname,
	ComPtr<ABI::WRLCompV1::IAddress> pIAddress,
	const wchar_t* wsStreet,
	const wchar_t* wsCity,
	const wchar_t* wsStreet2,
	const wchar_t* wsCity2)
{
	// Get the IPerson interface of ICitizen
	ComPtr<ABI::WRLCompV1::IPerson> pIPerson;
	HRESULT hr = pICitizen.As(&pIPerson);
	Assert::IsTrue(SUCCEEDED(hr));

	// Test the IPerson (of ICitizen...)
	TestIPerson(pIPerson, wsName, wsSurname);

	ComPtr<ABI::WRLCompV1::IAddress> pCitizenAddress;
	hr = pICitizen->get_Address(&pCitizenAddress);
	Assert::IsTrue(SUCCEEDED(hr));

	// Test the integrated address
	TestIAddress(pCitizenAddress,  wsStreet, wsCity);

	// Test the separate address
	TestIAddress(pIAddress, wsStreet2, wsCity2);

	// Set Address of Citizen with the separate address
	hr = pICitizen->put_Address(pIAddress.Get());
	Assert::IsTrue(SUCCEEDED(hr));

	// Get the Address of Citizen
	hr = pICitizen->get_Address(&pCitizenAddress);
	Assert::IsTrue(SUCCEEDED(hr));

	HSTRING hStreet;
	HSTRING hCity;

	// Get the Street and the City
	TestGetProperty(pCitizenAddress, Street, hStreet);
	TestGetProperty(pCitizenAddress, City, hCity);

	HString street;
	HString city;
	street.Set(hStreet);
	city.Set(hCity);

	// Validate the test
	Assert::AreEqual(wsStreet2, street.GetRawBuffer(nullptr));
	Assert::AreEqual(wsCity2, city.GetRawBuffer(nullptr));
}

		void TestISaveable(ComPtr<ABI::WRLCompV1::IPerson> pIPersonWrl)
		{
			// Get the ISaveable interface
			ComPtr<ABI::WRLCompV1::ISaveable> pISaveableWrl;
			HRESULT hr = pIPersonWrl.As(&pISaveableWrl);
			Assert::IsTrue(SUCCEEDED(hr));

			// Call the can save method
			boolean canSave;
			hr = pISaveableWrl->CanSave(&canSave);

			Assert::IsTrue(canSave);
		}

		void TestIAddress(ComPtr<ABI::WRLCompV1::IAddress> pIAddress, 
			const wchar_t* wsStreet,
			const wchar_t* wsCity)
		{
			HRESULT hr;
			HString street;
			HString city;
			street.Set(wsStreet);
			city.Set(wsCity);

			// Set the Street and the City
			TestPutProperty(pIAddress, Street, street);
			TestPutProperty(pIAddress, City, city);

			HSTRING hStreet;
			HSTRING hCity;

			// Get the Street and the City
			TestGetProperty(pIAddress, Street, hStreet);
			TestGetProperty(pIAddress, City, hCity);

			street.Set(hStreet);
			city.Set(hCity);

			// Validate the test
			Assert::AreEqual(wsStreet, street.GetRawBuffer(nullptr));
			Assert::AreEqual(wsCity, city.GetRawBuffer(nullptr));
		}

		void TestIPerson(ComPtr<ABI::WRLCompV1::IPerson> pIPersonWrl, 
			const wchar_t* wsName, 
			const wchar_t* wsSurname)
		{
			HString name;
			HString surname;
			name.Set(wsName);
			surname.Set(wsSurname);

			// Set the name and the surname
			HRESULT hr = pIPersonWrl->put_Name(name.Get());
			Assert::IsTrue(SUCCEEDED(hr));				

			hr = pIPersonWrl->put_Surname(surname.Get());
			Assert::IsTrue(SUCCEEDED(hr));		

			HSTRING hName;
			HSTRING hSurname;

			// Get the name and the surname
			hr = pIPersonWrl->get_Name(&hName);
			Assert::IsTrue(SUCCEEDED(hr));		

			hr = pIPersonWrl->get_Surname(&hSurname);
			Assert::IsTrue(SUCCEEDED(hr));

			name.Set(hName);
			surname.Set(hSurname);

			// Validate the test
			Assert::AreEqual(wsName, name.GetRawBuffer(nullptr));
			Assert::AreEqual(wsSurname, surname.GetRawBuffer(nullptr));
		}
    };
}