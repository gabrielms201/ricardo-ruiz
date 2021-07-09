using System;
using Microsoft.EntityFrameworkCore.Migrations;

namespace Cadastro.WebAPI.Migrations
{
    public partial class cinco : Migration
    {
        protected override void Up(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DeleteData(
                table: "Users",
                keyColumn: "Id",
                keyValue: "dasdas");

            migrationBuilder.InsertData(
                table: "Users",
                columns: new[] { "Id", "Age", "CreationDate", "FirstName", "Surname" },
                values: new object[] { "000", 18, new DateTime(2021, 7, 8, 1, 41, 23, 75, DateTimeKind.Local).AddTicks(7410), "Ric", "Ruiz" });
        }

        protected override void Down(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DeleteData(
                table: "Users",
                keyColumn: "Id",
                keyValue: "000");

            migrationBuilder.InsertData(
                table: "Users",
                columns: new[] { "Id", "Age", "CreationDate", "FirstName", "Surname" },
                values: new object[] { "dasdas", 23, new DateTime(2021, 7, 8, 1, 2, 8, 110, DateTimeKind.Local).AddTicks(6275), "ric", "ruiz" });
        }
    }
}
