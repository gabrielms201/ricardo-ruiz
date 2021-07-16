using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Xamarin.Forms;
using Xamarin.Forms.Xaml;
using Cadastro.App.Entities;
using Cadastro.App.Services;
using System.Net.Http;

namespace Cadastro.App
{
	[XamlCompilation(XamlCompilationOptions.Compile)]
	public partial class UserRegisterPage : ContentPage
	{
		ApiService ApiService;
		public UserRegisterPage()
		{
			ApiService = new ApiService();
			InitializeComponent();
			Title = "Registrar Usuário";
		}
		private void Button_Pressed(object sender, EventArgs e)
		{
			_ = SendRegisterAsync(sender, e);
		}
		private async Task SendRegisterAsync(object sender, EventArgs e)
		{
			(sender as Button).Text = "Registrando...";
			
			try
			{
				User user = new User
				{
					Age = int.Parse(age.Text.ToString()),
					FirstName = firstName.Text,
					Surname = surname.Text ?? null,
				};
				if (user.Surname == "")
					user.Surname = null;

				await ApiService.PostUserAsync(user);
				await DisplayAlert("Cadastro Realizado com sucesso", "Clique em confirmar para voltar", "Confirmar");
				(sender as Button).Text = "Enviar Cadastro";
			}
			catch (Exception)
			{
				await DisplayAlert("Erro...", "Campos obrigatórios não foram preenchidos corretamente", "Confirmar");
				(sender as Button).Text = "Enviar Cadastro";
			}
			
		}


	}
}
