using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Xamarin.Forms;
using Xamarin.Forms.Xaml;

namespace Cadastro.App
{
	[XamlCompilation(XamlCompilationOptions.Compile)]
	public partial class UserRegisterPage : ContentPage
	{
		public UserRegisterPage()
		{
			InitializeComponent();
			Title = "Registrar Usuário";
		}

		private void SendRegister(object sender, EventArgs e)
		{
			(sender as Button).Text = age.Text;
		}
	}
}
