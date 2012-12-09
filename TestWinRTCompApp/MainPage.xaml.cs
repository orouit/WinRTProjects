using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using Windows.Foundation;
using Windows.Foundation.Collections;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Controls.Primitives;
using Windows.UI.Xaml.Data;
using Windows.UI.Xaml.Input;
using Windows.UI.Xaml.Media;
using Windows.UI.Xaml.Navigation;

using WinRTCompNet;

// The Blank Page item template is documented at http://go.microsoft.com/fwlink/?LinkId=234238

namespace TestWinRTCompApp
{
    /// <summary>
    /// An empty page that can be used on its own or navigated to within a Frame.
    /// </summary>
    public sealed partial class MainPage : Page
    {
        public MainPage()
        {
            this.InitializeComponent();
        }

        /// <summary>
        /// Invoked when this page is about to be displayed in a Frame.
        /// </summary>
        /// <param name="e">Event data that describes how this page was reached.  The Parameter
        /// property is typically used to configure the page.</param>
        protected override void OnNavigatedTo(NavigationEventArgs e)
        {
            Address address = new Address("Owen moisture farm", "45678", "Mos Esley");
            Citizen citizen = new Citizen("Luke", "Skywalker", address);
            //Citizen driver = new Citizen("Olivier", "ROUIT");
            //IAddress address = driver.Address;
            //address.Street = "72, Woodlands Drive, #2-29, Woodsvale"; ;
            //IAddress addressNew = driver.Address;
            //addressNew.Street = "26 Woodlands Crescent, #4-30, Northoak";

            //string street = driver.Address.Street;

            string street = citizen.Address.Street;
            string formattedName = citizen.FormatDisplay();

            this.DataContext = citizen;
        }
    }
}
