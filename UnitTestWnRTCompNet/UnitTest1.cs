using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Microsoft.VisualStudio.TestPlatform.UnitTestFramework;

namespace UnitTestWnRTCompNet
{
    [TestClass]
    public class UnitTest1
    {
        const string
            NAME_DARTH = "Darth",
            NAME_LUKE = "Luke",
            SURNAME_VADOR = "Vador",
            SURNAME_SKYWALKER = "Skywalker";
        const string
            STREET_DARTH = "Senate district",
            ZIP_DARTH = "13100",
            CITY_DARTH = "Coruscant";

        [TestMethod]
        public void TestMethodWinRTCompNet()
        {
            // C# WinRT Person
            WinRTCompNet.Person person = new WinRTCompNet.Person(NAME_DARTH, SURNAME_VADOR);

            Assert.AreEqual(NAME_DARTH, person.Name);

            // C++ WinRT IPerson interface
            WinRTCompV2.IPerson personItf;

            // C++ WinRT Person class
            WinRTCompV2.Person personV2 = new WinRTCompV2.Person(NAME_LUKE, SURNAME_SKYWALKER);

            // the interface is now implemented by the C# person
            personItf = person;
            Assert.AreEqual(NAME_DARTH, personItf.Name);
            Assert.AreEqual(SURNAME_VADOR, personItf.Surname);

            // the interface is now implemented by the C++ Person
            personItf = personV2;
            Assert.AreEqual(NAME_LUKE, personItf.Name);
            Assert.AreEqual(SURNAME_SKYWALKER, personItf.Surname);

            // Create a C# Address and Citizen
            WinRTCompNet.Address addressDarth = new WinRTCompNet.Address(STREET_DARTH, ZIP_DARTH, CITY_DARTH);
            WinRTCompNet.Citizen citizenDarth = new WinRTCompNet.Citizen(NAME_DARTH, SURNAME_VADOR, addressDarth);

            // This method is only in the C# Citizen component. The compiler has created 
            // a default interface for that component. This interface is NOT ICitizen
            string display = citizenDarth.FormatDisplay();

            // Put the C# Address in the IAddress C++ interface 
            WinRTCompV2.IAddress addressItf = citizenDarth.Address;
            Assert.AreEqual(STREET_DARTH, addressItf.Street);
            Assert.AreEqual(ZIP_DARTH, addressItf.ZipCode);
            Assert.AreEqual(CITY_DARTH, addressItf.City);

            // Put the C# Citizen in the ICitizen C++ interface. The method FormatDisplay() is not visible  
            WinRTCompV2.ICitizen citizenItf = citizenDarth;
            Assert.AreEqual(NAME_DARTH, citizenItf.Name);
            Assert.AreEqual(SURNAME_VADOR, citizenItf.Surname);
        }
    }
}
