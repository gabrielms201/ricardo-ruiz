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
		/*protected override void OnConfiguring(DbContextOptionsBuilder optionsBuilder)
		{
			optionsBuilder.UseSqlServer("Password=sa123456;Persist Security Info=True;User ID=sa;Initial Catalog=RegisterApp;Data Source=DESKTOP-SCRLE7P\\SQLEXPRESS");
		}*/
		protected override void OnModelCreating(ModelBuilder modelbuilder)
		{
			modelbuilder.Entity<User>().HasData(new User { Id = "000", Age = 18, CreationDate = DateTime.Now, FirstName = "Ric", Surname = "Ruiz" });
		}
	}
}
