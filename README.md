# Esse repositório contém 2 projetos:

<b>1 -)</b> O primeiro projeto foi feito em c# utilizando ASPNET Core, Entity Framework e Xamarin. O projeto é um simples aplicativo que possibilita o usuário enviar os dados cadastrados para um banco de dados através de uma api.

<b>2-)</b> O segundo projeto foi feito em c++ utilizando a biblioteca quickfix. O projeto possui duas partes: um cliente, e um servidor. Consiste em uma aplicação que simula o comportamento do envio de ordens (Seja de compra ou venda) de ativos da bolsa de valores utilizando do protocolo FIX.


<h1>Orientações sobre o projeto do simulador da bolsa de valores:</h1>
<h2>Tutorial para compilar o simulador da bolsa (tanto para o cliente quanto para o servidor):</h2>
Abra o arquivo, e dentro da pasta build, abra o terminal e digite o comando do cmake. 
<br>Comando utilizado no desenvolvimento para o compilador microsoft c++ e microsoft visual studio como ambiente de desenvolvimento integrado: <blockquote> <b>$ cmake -A Win32 -T v140 .. </b></blockquote>

<h2>Tutorial para executar o simulador da bolsa (tanto para o cliente quanto para o servidor):</h2>
O projeto possui um arquivo <r>.bar</b> que inicia as aplicações junto com o arquivo de configuração <b>(.cfg)</b> portanto, para executar a aplicação é necessário utilizar do arquivo <b>batch</b>disponível na pasta base. <b>Caso o arquivo <br>batch</b> não funcione, verifique se o projeto foi compilado no mesmo diretório que o arquivo <b>batch</b> aponta (assim como o arquivo .cfg): <blockquote><b> (Build\Debug\Simulador.Bolsa.Client.exe) </b></blockquote>Caso isso não aconteça, basta editar o caminho no próprio arquivo .bat para o caminho onde foi compilado o executável da aplicação.

