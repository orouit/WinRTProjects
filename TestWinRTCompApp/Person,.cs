using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using WinRTCompV2;

namespace WinRTCompNet
{
    public class Person : IPerson
    {
        protected string display = string.Empty;
        private string name = string.Empty;
        private string surname = string.Empty;

        public Person()
        {
        }

        public Person(string name, string surname)
        {
            this.name = name;
            this.surname = surname;
            FormatDisplay();
        }

        public string Name
        {
            get { return name; }
            set 
            { 
                name = value;
                FormatDisplay();
            }
        }

        public string Surname
        {
            get { return surname; }
            set 
            {
                surname = value;
                FormatDisplay();
            }
        }

        public bool CanSave()
        {
            return Name.Length > 0 && Surname.Length > 0;
        }

        private void FormatDisplay()
        {
            display = string.Format("{0} {1}", name, surname);
        }
    }
}
