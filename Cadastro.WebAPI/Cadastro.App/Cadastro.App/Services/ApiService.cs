using System;
using System.Collections.Generic;
using System.Net.Http;
using System.Text;
using System.Threading.Tasks;
using Xamarin.Essentials;
using Cadastro.App.Entities;
using Newtonsoft.Json;

namespace Cadastro.App.Services
{
	class ApiService
	{
		public HttpClient client = new HttpClient();
		public static string BaseAddress = DeviceInfo.Platform == DevicePlatform.Android ? "http://10.0.2.2:8090/api/users" : "http://localhost:8090/api/users";

		public async Task PostUserAsync(User user)
		{
			try
			{
				var uri = new Uri(string.Format(BaseAddress, user.Id));
				var data = JsonConvert.SerializeObject(user);
				var content = new StringContent(data, Encoding.UTF8, "application/json");

				HttpResponseMessage response = null;
				response = await client.PostAsync(uri, content);
				if (!response.IsSuccessStatusCode)
				{
					throw new Exception("Erro ao tentar adicionar o usuário.");
				}

			}
			catch (Exception)
			{
				throw new Exception("Erro ao tentar adicionar o usuário.");
			}
		}
	}
}
