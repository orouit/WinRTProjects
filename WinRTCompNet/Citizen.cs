using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using WinRTCompV2;

namespace WinRTCompNetDll
{
    public sealed class Citizen : ICitizen
    {
        IPerson person;

        public Citizen() 
        {
            this.person = new Person();
            ((ICitizen)this).Address = new Address();
        }

        public Citizen(string name, string surname, Address address) 
        {
            this.person = new Person(name, surname);
            ((ICitizen)this).Address = address;
        }

        IAddress ICitizen.Address
        {
            get;
            set;
        }

        string IPerson.Name
        {
            get { return person.Name; }
            set { person.Name = value; }
        }

        string IPerson.Surname
        {
            get { return person.Surname; }
            set { person.Surname = value; }
        }

        public bool CanSave()
        {
            return person.CanSave() && ((ICitizen)this).Address.CanSave();
        }
    }
}
