using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Microsoft.VisualStudio.TestPlatform.UnitTestFramework;

namespace UnitTestWinRTComp
{
    static class TestData
    {
        public const string
            TEXT_STR1 = "Owen Farm",
            TEXT_ZIP1 = "04400",
            TEXT_CTY1 = "Mos Eisly",
            TEXT_STR2 = "Senate Apartment Complex",
            TEXT_ZIP2 = "83100",
            TEXT_CTY2 = "Coruscant",
            TEXT_NAME1 = "Luke",
            TEXT_SURNAME1 = "Skywlaker",
            TEXT_NAME2 = "Darth",
            TEXT_SURNAME2 = "Vador";
    }

    [TestClass]
    public class UnitTestMixCompV2V2b
    {

        [TestMethod]
        public void UnitTestMixingCompV2withCompV2b()
        {
            WinRTCompV2.IAddress addressV2 = new WinRTCompV2.Address(TestData.TEXT_STR1, TestData.TEXT_ZIP1, TestData.TEXT_CTY1);
            WinRTCompV2.IAddress addressV2b = new WinRTCompV2.Address2(TestData.TEXT_STR1, TestData.TEXT_ZIP1, TestData.TEXT_CTY1);

            WinRTCompV2.ICitizen citizenV2 = new WinRTCompV2.Citizen(TestData.TEXT_NAME1, TestData.TEXT_SURNAME1);
            WinRTCompV2.ICitizen citizenV2b = new WinRTCompV2.Citizen2(TestData.TEXT_NAME2, TestData.TEXT_SURNAME2);

            citizenV2.Address = addressV2b;
            addressV2b.ZipCode = TestData.TEXT_ZIP2;
            string zip2 = citizenV2b.Address.ZipCode;
            Assert.AreNotEqual(TestData.TEXT_ZIP2, zip2);

            citizenV2b.Address = addressV2;
            addressV2b.ZipCode = TestData.TEXT_ZIP1;
            string zip2b = citizenV2.Address.ZipCode;
            Assert.AreEqual(TestData.TEXT_ZIP1, zip2b);
        }
    }

    [TestClass]
    public class UnitTestWinRTCompMixV2V3
    {
        [TestMethod]
        public void UnitTestMixingWinRTCompV2withWinRTCompV3()
        {
            WinRTCompV2.IAddress addressV2 = new WinRTCompV2.Address(TestData.TEXT_STR1, TestData.TEXT_ZIP1, TestData.TEXT_CTY1);
            WinRTCompV2.IAddress addressV3 = new WinRTCompV3.Address(TestData.TEXT_STR2, TestData.TEXT_ZIP2, TestData.TEXT_CTY2);

            WinRTCompV2.ICitizen citizenV2 = new WinRTCompV2.Citizen(TestData.TEXT_NAME1, TestData.TEXT_SURNAME1);
            WinRTCompV2.ICitizen citizenV3 = new WinRTCompV3.Citizen(TestData.TEXT_NAME2, TestData.TEXT_SURNAME2);

            citizenV2.Address = addressV2;
            addressV2.ZipCode = TestData.TEXT_ZIP2;

            string zip2 = citizenV2.Address.ZipCode;
            Assert.AreEqual(TestData.TEXT_ZIP2, zip2);

            citizenV3.Address = addressV3;
            addressV3.ZipCode = TestData.TEXT_ZIP1;

            string zip3 = citizenV3.Address.ZipCode;
            Assert.AreEqual(TestData.TEXT_ZIP1, zip3);

            // Mixing Address V3 with Citizen V2
            citizenV2.Address = addressV3;
            addressV3.Street = TestData.TEXT_STR1;

            // The Street property has been changed AFTER the Address V3 was used for the Citizen V2
            string street2 = citizenV2.Address.Street;

            // Because it was not possible to create the association at the composition classes level,
            // the Street value in Citizen.Address is not updated.
            Assert.IsFalse(TestData.TEXT_STR1 == citizenV2.Address.Street);

            // However it is possible to mix V2 with V3 because in the V3 implementation the association
            // is between WinRT instances only
            citizenV3.Address = addressV2;
            addressV2.City = TestData.TEXT_CTY2;
            string city3 = citizenV3.Address.City;
            Assert.IsTrue(TestData.TEXT_CTY2 == citizenV3.Address.City);
        }
    }

    [TestClass]
    public class UnitTestWinRTCompV3
    {
        [TestMethod]
        public void TestPersonV3()
        {
            WinRTCompV2.IPerson person = new WinRTCompV3.Person();

            Assert.IsFalse(person.CanSave());

            person.Name = TestData.TEXT_NAME1;
            person.Surname = TestData.TEXT_SURNAME1;

            Assert.IsTrue(person.CanSave());

            Assert.AreEqual(TestData.TEXT_NAME1, person.Name);
            Assert.AreEqual(TestData.TEXT_SURNAME1, person.Surname);

            person = new WinRTCompV3.Person(TestData.TEXT_NAME2, TestData.TEXT_SURNAME1);

            Assert.IsTrue(person.CanSave());

            Assert.AreEqual(TestData.TEXT_NAME2, person.Name);
            Assert.AreEqual(TestData.TEXT_SURNAME1, person.Surname);

            person.Name = TestData.TEXT_NAME1;

            Assert.AreEqual(TestData.TEXT_NAME1, person.Name);
            Assert.AreEqual(TestData.TEXT_SURNAME1, person.Surname);
        }

        [TestMethod]
        public void TestAddressV3()
        {
            WinRTCompV2.IAddress address = new WinRTCompV3.Address();
            Assert.AreEqual("", address.Street);

            Assert.IsFalse(address.CanSave());

            address.Street = TestData.TEXT_STR1;
            address.ZipCode = TestData.TEXT_ZIP1;
            address.City = TestData.TEXT_CTY1;

            Assert.AreEqual(TestData.TEXT_STR1, address.Street);
            Assert.AreEqual(TestData.TEXT_ZIP1, address.ZipCode);
            Assert.AreEqual(TestData.TEXT_CTY1, address.City);

            address.Street = TestData.TEXT_STR2;
            address.ZipCode = TestData.TEXT_ZIP2;
            address.City = TestData.TEXT_CTY2;

            Assert.AreEqual(TestData.TEXT_STR2, address.Street);
            Assert.AreEqual(TestData.TEXT_ZIP2, address.ZipCode);
            Assert.AreEqual(TestData.TEXT_CTY2, address.City);

            Assert.IsTrue(address.CanSave());
        }

        [TestMethod]
        public void TestCitizenV3()
        {
            WinRTCompV2.ICitizen citizen1 = new WinRTCompV3.Citizen(TestData.TEXT_NAME1, TestData.TEXT_SURNAME1);

            Assert.IsFalse(citizen1.CanSave());
            Assert.AreEqual(TestData.TEXT_NAME1, citizen1.Name);
            Assert.AreEqual(TestData.TEXT_SURNAME1, citizen1.Surname);

            WinRTCompV2.IAddress address = citizen1.Address;
            address.City = TestData.TEXT_CTY1;
            address.Street = TestData.TEXT_STR1;
            address.ZipCode = TestData.TEXT_ZIP1;

            Assert.IsTrue(citizen1.CanSave());

            Assert.AreEqual(TestData.TEXT_CTY1, citizen1.Address.City);
            Assert.AreEqual(TestData.TEXT_STR1, citizen1.Address.Street);
            Assert.AreEqual(TestData.TEXT_ZIP1, citizen1.Address.ZipCode);

            WinRTCompV3.Address address2 = new WinRTCompV3.Address();
            WinRTCompV2.ICitizen citizen2 = new WinRTCompV3.Citizen(TestData.TEXT_NAME2, TestData.TEXT_SURNAME2, address2);

            Assert.IsFalse(citizen2.CanSave());
            Assert.AreEqual(TestData.TEXT_NAME2, citizen2.Name);
            Assert.AreEqual(TestData.TEXT_SURNAME2, citizen2.Surname);

            address2.City = TestData.TEXT_CTY2;
            address2.Street = TestData.TEXT_STR2;
            address2.ZipCode = TestData.TEXT_ZIP2;

            Assert.AreEqual(TestData.TEXT_CTY2, citizen2.Address.City);
            Assert.AreEqual(TestData.TEXT_STR2, citizen2.Address.Street);
            Assert.AreEqual(TestData.TEXT_ZIP2, citizen2.Address.ZipCode);
        }
    }

    [TestClass]
    public class UnitTestWRLCompV1
    {
        [TestMethod]
        public void TestWRLPerson()
        {
            WRLCompV1.PersonClass person = new WRLCompV1.PersonClass();

            person.Name = TestData.TEXT_NAME1;
            person.Surname = TestData.TEXT_SURNAME1;

            Assert.AreEqual(TestData.TEXT_NAME1, person.Name);
            Assert.AreEqual(TestData.TEXT_SURNAME1, person.Surname);
        }
    }

    [TestClass]
    public class UnitTestWinRTCompV2
    {
        [TestMethod]
        public void TestAddressV2()
        {
            WinRTCompV2.IAddress address = new WinRTCompV2.Address();
            Assert.AreEqual("", address.Street);

            Assert.IsFalse(address.CanSave());

            address.Street = TestData.TEXT_STR1;
            address.ZipCode = TestData.TEXT_ZIP1;
            address.City = TestData.TEXT_CTY1;

            Assert.AreEqual(TestData.TEXT_STR1, address.Street);
            Assert.AreEqual(TestData.TEXT_ZIP1, address.ZipCode);
            Assert.AreEqual(TestData.TEXT_CTY1, address.City);

            address.Street = TestData.TEXT_STR2;
            address.ZipCode = TestData.TEXT_ZIP2;
            address.City = TestData.TEXT_CTY2;

            Assert.AreEqual(TestData.TEXT_STR2, address.Street);
            Assert.AreEqual(TestData.TEXT_ZIP2, address.ZipCode);
            Assert.AreEqual(TestData.TEXT_CTY2, address.City);

            Assert.IsTrue(address.CanSave());
        }

        [TestMethod]
        public void TestPersonV2()
        {
            WinRTCompV2.IPerson person = new WinRTCompV2.Person();

            Assert.IsFalse(person.CanSave());

            person.Name = TestData.TEXT_NAME1;
            person.Surname = TestData.TEXT_SURNAME1;

            Assert.IsTrue(person.CanSave());

            Assert.AreEqual(TestData.TEXT_NAME1, person.Name);
            Assert.AreEqual(TestData.TEXT_SURNAME1, person.Surname);

            person = new WinRTCompV2.Person(TestData.TEXT_NAME2, TestData.TEXT_SURNAME1);

            Assert.IsTrue(person.CanSave());

            Assert.AreEqual(TestData.TEXT_NAME2, person.Name);
            Assert.AreEqual(TestData.TEXT_SURNAME1, person.Surname);

            person.Name = TestData.TEXT_NAME1;

            Assert.AreEqual(TestData.TEXT_NAME1, person.Name);
            Assert.AreEqual(TestData.TEXT_SURNAME1, person.Surname);
        }

        [TestMethod]
        public void TestCitizenV2()
        {
            WinRTCompV2.ICitizen citizen1 = new WinRTCompV2.Citizen(TestData.TEXT_NAME1, TestData.TEXT_SURNAME1);

            Assert.IsFalse(citizen1.CanSave());
            Assert.AreEqual(TestData.TEXT_NAME1, citizen1.Name);
            Assert.AreEqual(TestData.TEXT_SURNAME1, citizen1.Surname);

            WinRTCompV2.IAddress address = citizen1.Address;
            address.City = TestData.TEXT_CTY1;
            address.Street = TestData.TEXT_STR1;
            address.ZipCode = TestData.TEXT_ZIP1;

            Assert.IsTrue(citizen1.CanSave());

            Assert.AreEqual(TestData.TEXT_CTY1, citizen1.Address.City);
            Assert.AreEqual(TestData.TEXT_STR1, citizen1.Address.Street);
            Assert.AreEqual(TestData.TEXT_ZIP1, citizen1.Address.ZipCode);

            WinRTCompV2.Address address2 = new WinRTCompV2.Address();
            WinRTCompV2.ICitizen citizen2 = new WinRTCompV2.Citizen(TestData.TEXT_NAME2, TestData.TEXT_SURNAME2, address2);

            Assert.IsFalse(citizen2.CanSave());
            Assert.AreEqual(TestData.TEXT_NAME2, citizen2.Name);
            Assert.AreEqual(TestData.TEXT_SURNAME2, citizen2.Surname);

            address2.City = TestData.TEXT_CTY2;
            address2.Street = TestData.TEXT_STR2;
            address2.ZipCode = TestData.TEXT_ZIP2;

            Assert.AreEqual(TestData.TEXT_CTY2, citizen2.Address.City);
            Assert.AreEqual(TestData.TEXT_STR2, citizen2.Address.Street);
            Assert.AreEqual(TestData.TEXT_ZIP2, citizen2.Address.ZipCode);
        }
    }
}
