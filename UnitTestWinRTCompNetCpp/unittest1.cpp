#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace WinRTCompNet;

#define NAME_DARTH L"Darth"
#define SURNAME_VADOR L"Vador"
#define STREET_DARTH L"Senate district"
#define ZIP_DARTH L"13100"
#define CITY_DARTH L"Coruscant";

namespace UnitTestWinRTCompNetCpp
{
    TEST_CLASS(UnitTestWinRTCompNet)
    {
    public:
        TEST_METHOD(TestMethodWinRTCompNetCpp)
        {
            // TODO: Your test code here
			Address^ address = ref new Address();
			address->Street = STREET_DARTH;
			address->ZipCode = ZIP_DARTH;
			address->City = CITY_DARTH;
        }
    };
}