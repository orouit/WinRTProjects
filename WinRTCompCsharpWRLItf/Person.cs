using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using WRLCompV1;

namespace WinRTCompCsharpWRLItf
{
    /// <summary>
    /// The class Person implements in C# the following interfaces of WRLCompV1 namespace:
    ///     - IAddress
    ///     - ISaveable
    /// </summary>
    public sealed class Person : IPerson, ISaveable
    {
        private string name = string.Empty;
        private string surname = string.Empty;

        #region Explicit implementation of IPerson

        string IPerson.Name
        {
            get
            {
                return name;
            }
            set
            {
                name = value;
            }
        }

        string IPerson.Surname
        {
            get
            {
                return surname;
            }
            set
            {
                surname = value;
            }
        }

        #endregion

        #region Explicit implementation of ISaveable

        bool ISaveable.CanSave()
        {
            return name.Length > 0 && surname.Length > 0;
        }

        #endregion
    }
}
