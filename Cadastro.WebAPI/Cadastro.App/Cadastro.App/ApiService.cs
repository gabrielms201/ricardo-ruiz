using System;
using System.Collections.Generic;
using System.Text;
using Xamarin.Essentials;

namespace Cadastro.App
{
	class ApiService
	{
		public static string BaseAddress =
		DeviceInfo.Platform == DevicePlatform.Android ? "http://10.0.2.2:5001" : "http://localhost:8090";
		public static string Users = $"{BaseAddress}/api/Users/";
	}
}
