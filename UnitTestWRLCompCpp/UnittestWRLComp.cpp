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
#define TEXT_ZIP1		L"04400"
#define TEXT_CTY1		L"Mos Eisly"
#define TEXT_STR2		L"Senate Apartment Complex"
#define TEXT_ZIP2		L"83100"
#define TEXT_CTY2		L"Coruscant"
#define TEXT_NAME1		L"Luke"
#define TEXT_SURNAME1	L"Skywlaker"
#define TEXT_NAME2		L"Darth"
#define TEXT_SURNAME2	L"Vador"
#define TEXT_NAME3		L"Obi-Wan"
#define TEXT_SURNAME3	L"Kenobi"

namespace UnitTestWRLCompCpp
{
    TEST_CLASS(UnitTestCompWRL)
    {
    public:
        TEST_METHOD(TestCompV1WithWRL)
        {
			// Activate the WRLCompV1.Person that implements ABI::WRLCompV1::IPerson
			ComPtr<ABI::WRLCompV1::IPerson> pIPersonWrl;

			CreateIPerson(L"WRLCompV1.PersonClass", &pIPersonWrl);

			TestIPerson(pIPersonWrl, TEXT_NAME1, TEXT_SURNAME1);

			TestISaveable(pIPersonWrl);
        }

        TEST_METHOD(TestCompV1ItfWinRTCompCpp)
        {
			// Activate the WinRTCompWRLItf.Person that implements ABI::WRLCompV1::IPerson
			ComPtr<ABI::WRLCompV1::IPerson> pIPersonWrl;
			CreateIPerson(L"WinRTCompWRLItf.Person", &pIPersonWrl);

			TestIPerson(pIPersonWrl, TEXT_NAME2, TEXT_SURNAME2);

			TestISaveable(pIPersonWrl);
		}

        TEST_METHOD(TestCompV1ItfWinRTCompCsharp)
        {
			// Activate the WinRTCompCsharpWRLItf.Person that implements ABI::WRLCompV1::IPerson
			ComPtr<ABI::WRLCompV1::IPerson> pIPersonWrl;

			CreateIPerson(L"WinRTCompCsharpWRLItf.Person", &pIPersonWrl);

			TestIPerson(pIPersonWrl, TEXT_NAME3, TEXT_SURNAME3);

			TestISaveable(pIPersonWrl);
		}

	private:
		void CreateIPerson(const wchar_t* activableClassId, ::Microsoft::WRL::Details::ComPtrRef<ComPtr<ABI::WRLCompV1::IPerson>> pIPerson)
		{
			HStringReference runtimeClassPerson(activableClassId);

			HRESULT hr = Windows::Foundation::ActivateInstance< ComPtr<ABI::WRLCompV1::IPerson>>( runtimeClassPerson.Get(), pIPerson );
			Assert::IsTrue(SUCCEEDED(hr));
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

		void TestIPerson(ComPtr<ABI::WRLCompV1::IPerson> pIPersonWrl, wchar_t* wsName, wchar_t* wsSurname)
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