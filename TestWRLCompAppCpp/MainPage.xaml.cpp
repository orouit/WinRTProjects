//
// MainPage.xaml.cpp
// Implementation of the MainPage class.
//

#include "pch.h"
#include "MainPage.xaml.h"
#include "..\WRLCompV1\WRLCompV1_h.h"
#include <Windows.Foundation.h>
#include <wrl\wrappers\corewrappers.h>
#include <wrl\client.h>
#include <stdio.h>

using namespace TestWRLCompAppCpp;
using namespace ABI::Windows::Foundation;
using namespace Microsoft::WRL;
using namespace Microsoft::WRL::Wrappers;


using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;

// The Blank Page item template is documented at http://go.microsoft.com/fwlink/?LinkId=234238

MainPage::MainPage()
{
	InitializeComponent();
}

/// <summary>
/// Invoked when this page is about to be displayed in a Frame.
/// </summary>
/// <param name="e">Event data that describes how this page was reached.  The Parameter
/// property is typically used to configure the page.</param>
void MainPage::OnNavigatedTo(NavigationEventArgs^ e)
{
	(void) e;	// Unused parameter

	// Just for testing: Create my IPerson component
	HStringReference runtimeClassPerson(L"WRLCompV1.PersonClass");
	ComPtr<ABI::WRLCompV1::IPerson> pIPersonWrl;
	HRESULT hr = Windows::Foundation::ActivateInstance< ComPtr<ABI::WRLCompV1::IPerson>>( runtimeClassPerson.Get(), &pIPersonWrl );
	if (!SUCCEEDED(hr))
	{
		throw ref new FailureException("Failed to ActivateInstance of WRLCompV1.PersonClass");  
	}

}
