using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using WRLCompV1;

namespace WinRTCompCsharpWRLItf
{
    /// <summary>
    /// The class Citizen implements in C# the following interfaces of WRLCompV1 namespace:
    ///     - ICitizen
    ///     - IPerson
    ///     - ISaveable
    /// </summary>
    public sealed class Citizen : ICitizen, IPerson, ISaveable
    {
        private IPerson person;
        private IAddress address;

        public Citizen()
        {
            person = new Person();
            address = new Address();
        }

        #region Explicit implementation of IPerson

        string IPerson.Name
        {
            get
            {
                return person.Name;
            }
            set
            {
                person.Name = value;
            }
        }

        string IPerson.Surname
        {
            get
            {
                return person.Surname;
            }
            set
            {
                person.Surname = value;
            }
        }

        #endregion

        #region Explicit implementation of ICitizen

        IAddress ICitizen.Address
        {
            get
            {
                return address;
            }
            set
            {
                address = value;
            }
        }

        string ICitizen.Name
        {
            get
            {
                return ((IPerson) this).Name;
            }
            set
            {
                ((IPerson)this).Name = value;
            }
        }

        string ICitizen.Surname
        {
            get
            {
                return ((IPerson)this).Surname;
            }
            set
            {
                ((IPerson)this).Surname = value; ;
            }
        }

        #endregion

        #region Explicit implementation of ISaveable

        public bool CanSave()
        {
            return
                ((ISaveable)person).CanSave() &&
                ((ISaveable)address).CanSave();
        }

        #endregion
    }
}
