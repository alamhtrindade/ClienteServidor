#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#define PORTA 4477

int main(){
	
	int clienteSocket;
	char resposta[1024];
	struct sockaddr_in servidorSocket;
	
	
	/* CRIA UM CLIENTE SOCKET */
	clienteSocket = socket(PF_INET, SOCK_STREAM, 0);
	
	/*CABEÇALHO DA BIBLIOTECA */
	servidorSocket.sin_family = AF_INET;
	servidorSocket.sin_port = htons(PORTA);
	servidorSocket.sin_addr.s_addr = inet_addr("127.0.0.1");
	
	printf("CONECTANDO AO SERVIDOR\n");
	/*CONECTA AO SERVIDOR */
	connect(clienteSocket, (struct sockaddr*)&servidorSocket, sizeof(servidorSocket));
	
	/* RECEBE A RESPOSTA DO SERVIDOR */
	recv(clienteSocket, resposta, 1024, 0);
	printf("Resposta do Servidor: %s\n", resposta);
	
	printf("CONEXÃO ENCERRADA!\n");
	return 0;
}
