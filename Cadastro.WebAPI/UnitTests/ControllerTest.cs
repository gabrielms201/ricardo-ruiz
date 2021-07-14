using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;
using Microsoft.Extensions.Logging;
using Microsoft.EntityFrameworkCore;
using Cadastro.WebAPI.Data;
using Cadastro.WebAPI.Models;
using Xunit;
using Moq;
using System.Net;
using FluentAssertions;

namespace Cadastro.WebAPI.Controllers
{
	public class ControllerTest : DbContext
	{
		private UsersController _usersController;
		public ControllerTest()
		{
			_usersController = new UsersController(
				new Mock<UserContext>().Object, // Mock da DB
				new Mock<ILogger<UsersController>>().Object); // Mock do Logger
		}
		[Fact] //Teste com o post
		public async Task TestPostAsync()
		{
			Exception emptyObrigatoryFields = await Assert.ThrowsAsync<Exception>(() => _usersController.PostUser(
				new User { FirstName = null, Age = null, Surname = null }));
			Assert.Equal("Faltaram campos obrigatórios para serem preenchidos.", emptyObrigatoryFields.Message);
		}

		[Fact] // Teste com o get por id
		public async Task TestGetAsync()
		{
			Exception nullUserId = await Assert.ThrowsAsync<Exception>(() => _usersController.GetUser(null));
			Assert.Equal("O Id do usuário não pode ser nulo!", nullUserId.Message);
		}

		[Fact] // Teste com o put
		public async Task TestPutAsync()
		{
			Exception nullUserId = await Assert.ThrowsAsync<Exception>(() => _usersController.GetUser(null));
			Assert.Equal("O Id do usuário não pode ser nulo!", nullUserId.Message);
		}

		[Fact] // Teste com delete
		public async Task TestDeleteAsync()
		{
			Exception nullUserId = await Assert.ThrowsAsync<Exception>(() => _usersController.GetUser(null));
			Assert.Equal("O Id do usuário não pode ser nulo!", nullUserId.Message);
		}

	}
}
