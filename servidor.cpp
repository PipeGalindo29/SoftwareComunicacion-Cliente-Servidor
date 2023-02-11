#include <stdio.h>
#include <winsock2.h>
#include <string.h>
#include <iostream>

using namespace std;

int main(int argc, char **argv) {

WSADATA wsaData;
SOCKET skt, skt2;
	
int iResult, longitud_cliente, recv_size, puerto = 55227, cantMensajes;
struct sockaddr_in server, cliente;
char menu[2000];
char pila_mensajes[2000][400]

// Inicializacion del Winsock --------------------------------------------------------------

cout<<"Iniciando Winsock..."<<endl;
iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
if (iResult != 0) {
    cout<<"Error al iniciar winsock"<<endl;
    exit(-1);
}
cout<<"Winsock Inicializado"<<endl;

// Creacion del Socket ----------------------------------------------------------------------

cout<<"Creando Socket..."<<endl;
if((skt = socket(AF_INET, SOCK_STREAM,0))==INVALID_SOCKET){
	cout<<"Error al iniciar socket"<<endl;
	exit(-1);
}
cout<<"Socket Creado"<<endl;

// Configuracion Sockador -------------------------------------------------------------------

server.sin_family = AF_INET;
server.sin_port = htons(puerto);
server.sin_addr.s_addr = INADDR_ANY;

// Realizar en Bind -------------------------------------------------------------------------

if(bind(skt,(struct sockaddr*)&server, sizeof(server)) == SOCKET_ERROR){
	cout<<"Error al realizar el blind"<<endl;
	exit(-1);
}
cout<<"Blind realizado"<<endl;

listen(skt,5);
cout<<"Esperando conexiones entrantes...."<<endl;

longitud_cliente = sizeof(struct sockaddr_in);
skt2 = accept(skt,(struct sockaddr*)&cliente,&longitud_cliente);
if(skt == INVALID_SOCKET){
	cout<<"Fallo al aceptar la conexion"<<endl;
}

system("CLS");
cout<<"Cliente "<<inet_ntoa(cliente.sin_addr)<<" conectado exitosamente"<<endl<<endl;


// Enviar mensaje --------------------------------------------------------------------------



system("pause");

closesocket(skt);



return 0;

}
