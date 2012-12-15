using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using WinRTCompV2;

namespace WinRTCompNetDll
{
    public sealed class Address : IAddress 
    {
        public Address()
        {
        }

        public Address(string street, string zipCode, string city)
        {
            ((IAddress)this).Street = street;
            ((IAddress)this).ZipCode = zipCode;
            ((IAddress)this).City = city;
        }

        string IAddress.City
        {
            get;
            set;
        }

        string IAddress.Street
        {
            get;
            set;
        }

        string IAddress.ZipCode
        {
            get;
            set;
        }

        public bool CanSave()
        {
            return ((IAddress)this).Street.Length > 0 && ((IAddress)this).ZipCode.Length > 0 && ((IAddress)this).City.Length > 0;
        }
    }
}
