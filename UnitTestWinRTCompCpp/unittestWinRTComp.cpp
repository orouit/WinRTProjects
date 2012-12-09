#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

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
    };
}