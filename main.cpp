#include <iostream>
#include <vector>
#include <fstream>
#include <ctype.h>
#include <time.h>

using namespace std; 


int cont = 1; /* Contador de clientes */
int cant=0, aux=0, datos[0]; /* cantidad de datos, variable para organizar y vector de datos*/

/* Frimas */
int Menu();

ofstream file; /* Crear archivo de nombre file, la coloco global para que una vez corra el programa no se cierre y deje guardar tantos datos que querramos */

/* ------------------------------------------ */

int main(int argc, char** argv) {
	file.open("C:/Users/pipeg/OneDrive/Escritorio/Trabajo C++/Clientes.txt"); /* Abrimos archivo .txt. IMPORTANTE cambia la direccion a tu escritotio */
	Menu();

	return 0;
}

/* ------------------------------------------ */


int Menu(){
	int op, cont2=0;
	
	time_t tiempoahora; /* funcion para usar el reloj de la computadora */
	
	cout<<"Cliente #"<<cont<<endl<<endl<<endl;
	
	cout<<"--------Menu--------"<<endl<<endl;
	cout<<"1. Ingresar arreglos"<<endl;
	cout<<"2. Ver datos con el metodo Monticula"<<endl;
	cout<<"3. Ver datos con el metodo Burbuja"<<endl;
	cout<<"4. Siguiente cliente"<<endl;
	cout<<"5. Finalizar proceso"<<endl<<endl;
	
	cout<<"Seleccione la opcion que desee: "; 
	cin>>op;
	
	switch(op){
		case 1: system("CLS");
				cout<<"Cliente #"<<cont<<endl<<endl<<endl;
				
				cout<<"Cuantos datos desea ingresar: ";
				cin>>cant;
				
				datos[cant]; /* extiende el vector a la cantidad que desea el cliente */
				
				for(int i=0;i<cant;i++){ /* recorre todo el vector y guarda un dato en cada posicion */
					cout<<"Ingrese el dato #"<<(i+1)<<" : ";
					cin>>datos[i];
					
					if(datos[i]==false){ /* verifica si el dato ingresado es de valor numerico */
						cout<<"Error, no ha ingresado un dato valido"<<endl<<endl; 
						i = cant; /* da a i el valor de cant para cerrar el ciclo for */
					}else{
						if(i == cant-1){
							cout<<"Los datos se han ingresado correctamente"<<endl<<endl;	
						}
					}
				}
				Menu(); /* vuelve a llamar al menu para seguir el proceso */
				break;
		
		case 2: system("CLS");
				cout<<"Cliente #"<<cont<<endl<<endl<<endl;
				
				int j,it,te,i,k; 
				
				for(k=cant;k>=0;k--){
					for(i=0;i<=k;i++){
						it=datos[i];
						j=i/2;
						while(j>0 && datos[j]<it){
							datos[i]=datos[j];
							i=j;
							j=j/2;
						}
						datos[i]=it;
					}
					te=datos[1];
					datos[1]=datos[k];
					datos[k]=te;
				}
				cout<<"El arreglo ordenado con el metodo Monticula es:"<<endl;
				
				for(int i=0;i<=cant-1;i++){
					for(int j=0;j<=cant-1;j++){
						if(datos[j]>datos[j+1]){
							aux = datos[j];
							datos[j] = datos[j+1];
							datos[j+1] = aux;
						}
					}
				}
				
				for(int i=0;i<=cant;i++){
					if(datos[i]<=0 and datos[i]!=32763){
						cout<<"";
					}else{
						cout<<datos[i]<<endl;
						}
					}
				cout<<endl<<endl;
				
				cout<<endl<<endl;
				Menu();
				break;
				
		case 3: system("CLS");
				cout<<"Cliente #"<<cont<<endl<<endl<<endl;
				
				
				for(int i=0;i<=cant-1;i++){
					for(int j=0;j<=cant-1;j++){
						if(datos[j]>datos[j+1]){
							aux = datos[j];
							datos[j] = datos[j+1];
							datos[j+1] = aux;
						}
					}
				}
							
				cout<<"El arreglo ordenado con el metodo Burbuja es:"<<endl;
				for(int i=0;i<=cant;i++){
					if(datos[i]<=0 and datos[i]!=32763){
						cout<<"";
					}else{
						cout<<datos[i]<<endl;
						}
					}
				cout<<endl<<endl;
				Menu();
				break;
		
		case 4: system("CLS"); /* Al entrar a la opcion 4, empezamos a modificar el archivo .txt con los datos del cliente */
				file<<"Cliente #"<<cont<<"\n";
				
				for(int i=0;i<=cant-1;i++){  /* recorremos todo el vector para ordenarlo nuevamente */
					for(int j=0;j<=cant-1;j++){
						if(datos[j]>datos[j+1]){
							aux = datos[j];
							datos[j] = datos[j+1];
							datos[j+1] = aux;
						}
					}
				}
							
				file<<"El arreglo del cliente #"<<cont<<" es:\n";
				for(int i=0;i<=cant;i++){
					if(datos[i]<=0 and datos[i]!=32763){ /* verificamos que no entren archivos basura */
						cout<<"";
					}else{
						file<<datos[i]<<"\n"; /* guardamos datos del vector ordenados y los escribimos en el archivo .txt */
						}
					}
					
				file<<"\n\n\n";
				
				file<<"Fecha de ingreso del cliente #"<<cont<<" : ";
				
				time(&tiempoahora);
				file<<("%s\n", ctime(&tiempoahora)); /* usamos el reloj de la computadora y lo escribimos en el archivo .txt */
				
				file<<"\n\n\n";
				
				/* Aumentamos a contador para decir que ya estamos con otro cliente */
				cont = cont+1;
				
				/* Volvemos a poner todas las variables en cero para empezar con el nuevo cliente */
				datos[0];
				cant = 0;
				Menu();
				break;
				
		case 5: system("CLS");
				
				/* Repetimos el mismo procedimiento que en el case 4 */
				
				file<<"Cliente #"<<cont<<"\n";
				
				for(int i=0;i<=cant-1;i++){
					for(int j=0;j<=cant-1;j++){
						if(datos[j]>datos[j+1]){
							aux = datos[j];
							datos[j] = datos[j+1];
							datos[j+1] = aux;
						}
					}
				}
							
				file<<"El arreglo del cliente #"<<cont<<" es:\n";
				for(int i=0;i<=cant;i++){
					if(datos[i]<=0 and datos[i]!=32763){
						cout<<"";
					}else{
						file<<datos[i]<<"\n";
						}
					}
					
				file<<"\n\n\n";
				
				file<<"Se han atendido "<<cont<<" clientes\n"; /* Ponemos la cantidad de clientes que hemos atendido */
				
				file<<"Fecha de ingreso del cliente #"<<cont<<" : ";
				
				time(&tiempoahora);
				file<<("%s\n", ctime(&tiempoahora));
				
				cout<<"Se guardaran todos los datos en un archivo .txt"<<endl;
				
				
				file.close(); /* Cerramos todo el archivo .txt para dejar de modificarlo */
				exit(1); /* Cerramos el programa como tal */
				break;
	}
	
}
