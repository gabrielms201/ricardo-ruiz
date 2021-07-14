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

namespace Cadastro.WebAPI.Controllers
{
    [Route("api/[controller]")]
    [ApiController]
    public class UsersController : ControllerBase
    {
        private readonly UserContext _context;
        private readonly ILogger _logger; 

        public UsersController(UserContext context, ILogger<UsersController> logger)
        {
            _context = context;
            _logger = logger;
        }

        // GET: api/Users
        [HttpGet]
        public async Task<ActionResult<IEnumerable<User>>> GetUsers()
        {
            _logger.LogInformation(MyLogEvents.ListItems, $"{DateTime.Now} - Utilizado get em todos os usuários");
            return await _context.Users.ToListAsync();
        }

        // GET: api/Users/id
        [HttpGet("{id}")]
        public async Task<ActionResult<User>> GetUser(string id)
        {
            if (id == null)
			{
                throw new Exception("O Id do usuário não pode ser nulo!");
			}

            _logger.LogInformation(MyLogEvents.GetItem, $"{DateTime.Now} - Utilizado get no usuário de id: {id}.");
            var user = await _context.Users.FindAsync(id);

            if (user == null)
            
            {
                _logger.LogWarning(MyLogEvents.GetItemNotFound, $"{DateTime.Now} - [ERRO] Tentativa de Get: Usuário de id {id} não encontrado.");
                return NotFound();
            }

            return user;
        }

        // PUT: api/Users/id
        [HttpPut("{id}")]
        public async Task<IActionResult> PutUser(string id, User user)
        {
            if (id == null)
            {
                throw new Exception("O Id do usuário não pode ser nulo!");
            }
            user.SetId(id);
            if (id != user.Id)
            {
                return BadRequest();
            }

            _context.Entry(user).State = EntityState.Modified;
            _context.Entry(user).Property(x => x.CreationDate).IsModified = false;
            _context.Entry(user).Property(x => x.Id).IsModified = false;
            try
            {
                _logger.LogInformation(MyLogEvents.UpdateItem, $"{DateTime.Now} - Modificado o usuário de id: {id}.");
                await _context.SaveChangesAsync();
            }
            catch (DbUpdateConcurrencyException)
            {
                if (!UserExists(id))
                {
                    _logger.LogWarning(MyLogEvents.UpdateItemNotFound, $"{DateTime.Now} - [ERRO] Tentativa de Update: Usuário de id {id} não encontrado.");
                    return NotFound();
                }
                else
                {
                    throw;
                }
            }

            return NoContent();
        }

        // POST: api/Users
        [HttpPost]
        public async Task<ActionResult<User>> PostUser(User user)
        {
            if (user.FirstName == null || user.Age  == null)
			{
                throw new Exception("Faltaram campos obrigatórios para serem preenchidos.");
			}

            user.SetDate(DateTime.Now);
            _context.Users.Add(user);
            try
            {
                _logger.LogInformation(MyLogEvents.InsertItem, $"{DateTime.Now} - Adicionado o usuário de id: {user.Id}.");
                await _context.SaveChangesAsync();
            }
            catch (DbUpdateException)
            {
                if (UserExists(user.Id))
                {
                    _logger.LogWarning(MyLogEvents.PostUserConflict, $"{DateTime.Now} - [ERRO] Tentativa de Post: Usuário de id {user.Id} já existente.");
                    return Conflict();
                }
                else
                {
                    throw;
                }
            }

            return CreatedAtAction("GetUser", new { id = user.Id }, user);
        }

        // DELETE: api/Users/5
        [HttpDelete("{id}")]
        public async Task<ActionResult<User>> DeleteUser(string id)
        {
            if (id == null)
                throw new Exception("O Id do usuário não pode ser nulo!");
            var user = await _context.Users.FindAsync(id);
            if (user == null)
            {
                _logger.LogWarning(MyLogEvents.DeleteItemNotFound, $"{DateTime.Now} - [ERRO] Tentativa de Delete: Usuário de id {id} não encontrado.");
                return NotFound();
            }

            _context.Users.Remove(user);
            _logger.LogInformation(MyLogEvents.DeleteItem, $"{DateTime.Now} - Removido o usuário de id: {id}");
            await _context.SaveChangesAsync();

            return user;
        }

        private bool UserExists(string id)
        {
            return _context.Users.Any(e => e.Id == id);
        }
    }
}
