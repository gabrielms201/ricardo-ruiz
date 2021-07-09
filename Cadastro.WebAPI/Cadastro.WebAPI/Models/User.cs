using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Threading.Tasks;

namespace Cadastro.WebAPI.Models
{
	public class User
	{
		[Key]
		public string Id { get; private set; }
		[Required(ErrorMessage = "Esse campo é obrigatório!")]
		public string FirstName { get; set; }
		public string Surname { get; set; }
		[Required(ErrorMessage = "Esse campo é obrigatório!")]
		[Range(1, int.MaxValue, ErrorMessage = "O valor deve ser maior que 0")]
		public int Age { get; set; }
		public DateTime CreationDate { get; private set; }
		public User()
		{
			Id = GetUserId();
			CreationDate = DateTime.Now;
		}
		public static string GetUserId()
		{
			Guid id = Guid.NewGuid();
			return id.ToString();
		}

	}
}
