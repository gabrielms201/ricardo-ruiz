    using System;
using Microsoft.EntityFrameworkCore.Migrations;

namespace Cadastro.WebAPI.Migrations
{
    public partial class quarta : Migration
    {
        protected override void Up(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.InsertData(
                table: "Users",
                columns: new[] { "Id", "Age", "CreationDate", "FirstName", "Surname" },
                values: new object[] { "dasdas", 23, new DateTime(2021, 7, 8, 1, 2, 8, 110, DateTimeKind.Local).AddTicks(6275), "ric", "ruiz" });
        }

        protected override void Down(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DeleteData(
                table: "Users",
                keyColumn: "Id",
                keyValue: "dasdas");
        }
    }
}
