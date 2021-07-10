using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Cadastro.WebAPI.Models;
using Microsoft.EntityFrameworkCore;

namespace Cadastro.WebAPI.Data
{
	public class UserContext : DbContext
	{
		public DbSet<User> Users { get; set; }

		public UserContext(DbContextOptions<UserContext> options) : base(options) { }
	}
}
