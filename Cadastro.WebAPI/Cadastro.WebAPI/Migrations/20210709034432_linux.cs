using System;
using Microsoft.EntityFrameworkCore.Migrations;

namespace Cadastro.WebAPI.Migrations
{
    public partial class linux : Migration
    {
        protected override void Up(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DeleteData(
                table: "Users",
                keyColumn: "Id",
                keyValue: "000");
        }

        protected override void Down(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.InsertData(
                table: "Users",
                columns: new[] { "Id", "Age", "CreationDate", "FirstName", "Surname" },
                values: new object[] { "000", 18, new DateTime(2021, 7, 8, 1, 41, 23, 75, DateTimeKind.Local).AddTicks(7410), "Ric", "Ruiz" });
        }
    }
}
