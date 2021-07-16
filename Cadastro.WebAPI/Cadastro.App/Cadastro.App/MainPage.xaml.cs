using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Xamarin.Forms;

namespace Cadastro.App
{
	public partial class MainPage : ContentPage
	{
		public MainPage()
		{
			InitializeComponent();
			Title = "Menu Principal";
		}

		void OpenUserRegister(object sender, EventArgs e)
		{
			Navigation.PushAsync(new UserRegisterPage());
		}
	}
}
