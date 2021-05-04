#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/types.h>
#define PORTA 4477

int main(){
	
	int novoSocket, socketLeitura;
	struct sockaddr_in servidorSocket, novoEnvio;
	char mensagem[1024], buffer[1024];
	socklen_t addr_size;
	
	/* CRIA UM SERVIDOR SOCKET */
	socketLeitura = socket(AF_INET, SOCK_STREAM, 0);

	/* CABEÇALHO CONFORME BIBLIOTECA SYS/SOCKET.H */
	servidorSocket.sin_family = AF_INET;
	servidorSocket.sin_port = htons(PORTA);
	servidorSocket.sin_addr.s_addr = inet_addr("127.0.0.1");

	/* ABRE UMA CONEXÃO PELA PORTA DEFINIDA */
	bind(socketLeitura, (struct sockaddr*)&servidorSocket, sizeof(servidorSocket));
	printf("AGUARDANDO UM CLIENTE SE CONECTAR...\n");

	/* AGUARDA UM CLIENTE SE CONECTAR A ESTA PORTA QUE FOI ABERTA PARA UMA NOVA CONEXÃO */
	listen(socketLeitura, 5);


	/* QUANDO SE CONECTA, O NOVO SOCKET É PREPARADO PARA ENVIO DA RESPOSTA*/
	novoSocket = accept(socketLeitura, (struct sockaddr*)&novoEnvio, &addr_size);
	printf("CLIENTE CONECTADO!!!\n");
	printf("DIGITE UMA RESPOSTA DO SERVIDOR AO CLIENTE: ");
	scanf("%[^\n]s",mensagem);
	
	strcpy(buffer, mensagem);
	send(novoSocket, mensagem, strlen(mensagem), 0);
	printf("TCHAUU BRIGADO!\n");

	return 0;


}
