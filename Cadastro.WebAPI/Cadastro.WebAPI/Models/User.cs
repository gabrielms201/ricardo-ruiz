using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace Cadastro.WebAPI.Models
{
	public class User
	{
		public string Id { get; set; }
		public string FirstName { get; set; }
		public string Surname { get; set; }
		public int Age { get; set; }
		public DateTime CreationDate { get; set; }
	}
}
