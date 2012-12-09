#pragma once

using namespace Platform;

namespace WinRTCompV1
{
	public interface class ISaveable
	{
		bool CanSave();
	};

	public interface class IAddress : ISaveable
	{
		property String^ Street;
	};

	public interface class IPerson : ISaveable
	{
		property String^ Name;
		property String^ Surname;
		property IAddress^ Address {
			IAddress^ get();
		};
	};
}