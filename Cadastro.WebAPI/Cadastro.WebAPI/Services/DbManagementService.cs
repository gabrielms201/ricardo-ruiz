using Microsoft.AspNetCore.Builder;
using Microsoft.Extensions.DependencyInjection;
using Microsoft.EntityFrameworkCore;
using Cadastro.WebAPI.Data;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace Cadastro.WebAPI.Services
{
	public class DbManagementService
	{
		public static void MigrationInitialization(IApplicationBuilder app)
		{
			using (var serviceScope = app.ApplicationServices.CreateScope())
			{
				serviceScope.ServiceProvider.GetService<UserContext>().Database.Migrate();
			}
		}
	}
}
