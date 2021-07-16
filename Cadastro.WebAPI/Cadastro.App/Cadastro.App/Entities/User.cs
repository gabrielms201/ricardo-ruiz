using System;
using System.Collections.Generic;
using System.Text;

namespace Cadastro.App.Entities
{
	class User
	{
		public string Id { get; private set; }
		public string FirstName { get; set; }
		public string Surname { get; set; }
		public int? Age { get; set; }
		public DateTime CreationDate { get; private set; }
	}
}
