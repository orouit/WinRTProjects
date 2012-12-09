using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using WinRTCompV2;

namespace WinRTCompNet
{
    public sealed class Citizen : Person, ICitizen
    {
        public Citizen() :
            base()
        {
            this.Address = new Address();
        }

        public Citizen(string name, string surname, Address address) :
            base(name, surname)
        {
            this.Address = address;
        }

        public IAddress Address
        {
            get;
            set;
        }

        public string FormatDisplay()
        {
            return display;
        }

        public bool CanSave()
        {
            return base.CanSave() && Address.CanSave();
        }
    }
}
