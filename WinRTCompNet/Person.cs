using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using WinRTCompV2;

namespace WinRTCompNetDll
{
    /// <summary>
    /// C# implementation of the WinRT component interface IPerson
    /// 
    /// This interface must be implemented EXPLICITLY to workaround a known 
    /// bug of the compiler. Fortunately this workaround wouldn't need a 
    /// modification once the issue is solved by Microsoft.
    /// </summary>
    public  sealed class Person : IPerson
    {
        #region Fields

        private string name;
        private string surname;

        #endregion

        #region Constructors

        public Person()
        {
        }

        public Person(string name, string surname)
        {
            this.name = name;
            this.surname = surname;
        }

        #endregion

        string IPerson.Name
        {
            get { return name; }
            set { name = value; }
        }

        string IPerson.Surname
        {
            get { return surname; }
            set { surname = value; }
        }

        public bool CanSave()
        {
            return name.Length > 0 && surname.Length > 0;
        }
    }
}
