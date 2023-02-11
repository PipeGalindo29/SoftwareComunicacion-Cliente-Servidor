#include <stdio.h>
#include <winsock2.h>
#include <string.h>
#include <iostream>

using namespace std;

int main(int argc, char **argv) {

WSADATA wsaData;
SOCKET skt, skt2;
	
int iResult, longitud_cliente, puerto = 55227;
struct sockaddr_in server, cliente;

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
server.sin_addr.s_addr = inet_addr("127.0.0.1");

if(connect(skt,(struct sockaddr*)&server, sizeof(server)) < 0){
	cout<<"Error de conexion"<<endl;
	exit(-1);
}
cout<<"Conexion exitosa"<<endl;

// Inicio -------------------------------------------------------------------------------------


closesocket(skt);



return 0;

}
