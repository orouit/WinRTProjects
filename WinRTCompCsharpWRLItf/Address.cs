using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using WRLCompV1;

namespace WinRTCompCsharpWRLItf
{
    /// <summary>
    /// The class Address implements in C# the following interfaces of WRLCompV1 namespace:
    ///     - IAddress
    ///     - ISaveable
    /// </summary>
    public sealed class Address : IAddress, ISaveable
    {
        private string street = string.Empty;
        private string city = string.Empty;

        #region Explicit implementation of IAddress

        string IAddress.City
        {
            get
            {
                return city;
            }
            set
            {
                city = value;
            }
        }

        string IAddress.Street
        {
            get
            {
                return street;
            }
            set
            {
                street = value;
            }
        }

        #endregion

        #region Explicit implementation of ISaveable

        bool ISaveable.CanSave()
        {
            return street.Length > 0 && city.Length > 0;
        }

        #endregion
    }
}
