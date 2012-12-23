#include "pch.h"
#include <Windows.Foundation.h>
#include <wrl\wrappers\corewrappers.h>
#include <wrl\client.h>
#include <stdio.h>
#include "..\WRLCompV1\WRLCompV1_h.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace ABI::Windows::Foundation;
using namespace Microsoft::WRL;
using namespace Microsoft::WRL::Wrappers;

#define TEXT_STR1		L"Owen Farm"
#define TEXT_ZIP1		L"04400"
#define TEXT_CTY1		L"Mos Eisly"
#define TEXT_STR2		L"Senate Apartment Complex"
#define TEXT_ZIP2		L"83100"
#define TEXT_CTY2		L"Coruscant"
#define TEXT_NAME1		L"Luke"
#define TEXT_SURNAME1	L"Skywlaker"
#define TEXT_NAME2		L"Darth"
#define TEXT_SURNAME2	L"Vador"

namespace UnitTestWinRTCompCpp
{
    TEST_CLASS(UnitTestWinRTComp)
    {
    public:
        TEST_METHOD(TestMethodCitizenV2)
        {
			WinRTCompV2::ICitizen^ citizenV2 = ref new WinRTCompV2::Citizen(TEXT_NAME1, TEXT_SURNAME1);
			WinRTCompV2::IAddress^ addressV2 = ref new WinRTCompV2::Address();

			citizenV2->Address = addressV2;
			addressV2->City = TEXT_CTY1;
			Assert::AreEqual(TEXT_CTY1, citizenV2->Address->City->Data());

			WinRTCompV2::IAddress^ addressV3 = ref new WinRTCompV3::Address();

			citizenV2->Address = addressV3;
			addressV3->City = TEXT_CTY2;
			Assert::AreNotEqual(TEXT_CTY2, citizenV2->Address->City->Data());
        }

        TEST_METHOD(TestMethodCitizenV2WithAddressV2b)
        {
			WinRTCompV2::ICitizen^ citizenV2 = ref new WinRTCompV2::Citizen(TEXT_NAME1, TEXT_SURNAME1);
			WinRTCompV2::IAddress^ addressV2 = ref new WinRTCompV2::Address();

			citizenV2->Address = addressV2;
			addressV2->City = TEXT_CTY1;
			Assert::AreEqual(TEXT_CTY1, citizenV2->Address->City->Data());

			WinRTCompV2::IAddress^ addressV2b = ref new WinRTCompV2::Address2();

			citizenV2->Address = addressV2b;
			addressV2b->City = TEXT_CTY2;
			Assert::AreNotEqual(TEXT_CTY2, citizenV2->Address->City->Data());
        }

		/**
			Test of the WRL component Person that implements IPerson and ISaveable

			This test uses the C++/CX extensions create and use the Person component
		 */
		TEST_METHOD(TestPersonWRLCompV1)
		{
			WRLCompV1::PersonClass^ personWrl = ref new WRLCompV1::PersonClass();

			personWrl->Name = TEXT_NAME1;
			personWrl->Surname = TEXT_SURNAME1;

			Assert::AreEqual(TEXT_NAME1, personWrl->Name);
			Assert::AreEqual(TEXT_SURNAME1, personWrl->Surname);

			WRLCompV1::ISaveable^ saveable = personWrl; 
			Assert::IsTrue(saveable->CanSave());
		}

		/**
			This test directly uses the WRL framework to create and use the Person component
		 */
		TEST_METHOD(TestCOMLikeLoadOfWinRTComponent)
		{
			// Activate an instance of Person and get the IPerson interface
			HStringReference runtimeClassPerson(L"WRLCompV1.PersonClass");
			ComPtr<ABI::WRLCompV1::IPerson> pIPersonWrl;
			HRESULT hr = Windows::Foundation::ActivateInstance< ComPtr<ABI::WRLCompV1::IPerson>>( runtimeClassPerson.Get(), &pIPersonWrl );
			Assert::IsTrue(SUCCEEDED(hr));

			HString name;
			HString surname;
			name.Set(TEXT_NAME1);
			surname.Set(TEXT_SURNAME1);

			// Set the name and the surname
			hr = pIPersonWrl->put_Name(name.Get());
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
			Assert::AreEqual(TEXT_NAME1, name.GetRawBuffer(nullptr));
			Assert::AreEqual(TEXT_SURNAME1, surname.GetRawBuffer(nullptr));

			// Get the ISaveable interface
			ComPtr<ABI::WRLCompV1::ISaveable> pISaveableWrl;
			hr = pIPersonWrl.As(&pISaveableWrl);

			Assert::IsTrue(SUCCEEDED(hr));

			// Call the can save method
			boolean canSave;
			hr = pISaveableWrl->CanSave(&canSave);

			Assert::IsTrue(canSave);
		}
    };
}