using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using WinRTCompV2;

namespace WinRTCompNet
{
    public sealed class Address : IAddress 
    {
        public Address()
        {
        }

        public Address(string street, string zipCode, string city)
        {
            this.Street = street;
            this.ZipCode = zipCode;
            this.City = city;
        }

        public string City
        {
            get;
            set;
        }

        public string Street
        {
            get;
            set;
        }

        public string ZipCode
        {
            get;
            set;
        }

        public bool CanSave()
        {
            return Street.Length > 0 && ZipCode.Length > 0 && City.Length > 0;
        }
    }
}
