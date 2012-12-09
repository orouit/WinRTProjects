#pragma once

using namespace Platform;

namespace WinRTCompV2
{
	/**
		@brief Defines the behavior of an object that can be saved.
	*/
	public interface class ISaveable
	{
		/**
			Check if the object can be saved

			@return  true if can be saved, false otherwise
		*/
		bool CanSave();
	};

	/**
		@brief Represents a simple address
	*/
	public interface class IAddress : ISaveable
	{
		/**
			Street element of the address
		*/
		property String^ Street;

		/**
			ZipCode of the address
		*/
		property String^ ZipCode;

		/**
			City of the address
		*/
		property String^ City;

	};

	/**
		@brief	Represents a simple person object
	*/
	public interface class IPerson : ISaveable
	{
		/**
			Name property for the person
		*/
		property String^ Name;

		/**
			Name property for the person
		*/
		property String^ Surname;
	};

	/**
		@brief Represents a citizen, defined as a person with an address
	*/
	public interface class ICitizen : IPerson
	{
		property IAddress^ Address;
	};
}