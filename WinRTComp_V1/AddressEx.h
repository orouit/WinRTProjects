#pragma once

using namespace Platform;

namespace WinRTComp
{
	class CAddress
	{
	private:
		String^ street;

	public:
		CAddress();
		CAddress(String^ street);

		void SetStreet(String^ const value );
		String^ GetStreet();
	};
}

