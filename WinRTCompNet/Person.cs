using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using WinRTCompV2;

namespace WinRTCompNet
{
    public sealed class Person : IPerson
    {
        #region Fields

        private string name;
        private string surname;

        #endregion

        #region Consttructors

        public Person()
        {
        }

        public Person(string name, string surname)
        {
            this.name = name;
            this.surname = surname;
        }

        #endregion

        public string Name
        {
            get;
            set;
        }

        public string Surname
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

        public bool CanSave()
        {
            return name.Length > 0 && surname.Length > 0;
        }
    }
}
