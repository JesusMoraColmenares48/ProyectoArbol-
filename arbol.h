// #include <conio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;
struct Nodo{
	int dato;
	Nodo *derecho;
	Nodo *izquiero;
};


void mostrarArbol(Nodo *arbol, int contador){
	
	if(arbol == NULL){
		return;
	}else{
		contador++;
		mostrarArbol(arbol->derecho,contador);
		for(int i = 0; i < contador; i++){
			cout<< "   ";
		}
		cout<<arbol->dato<<endl;
		contador++;
		mostrarArbol(arbol->izquiero, contador);
	}
}

Nodo *CrearNodo(int Dato){
	Nodo *nodo=new Nodo();	
	nodo->dato=Dato;
	nodo->derecho=NULL;
	nodo->izquiero=NULL;
	
	return nodo;
}

Nodo *ABB = NULL;

void insertar(Nodo *&arbol, int dato){
	
	if(arbol == NULL){
		Nodo *nodo_nuevo = CrearNodo(dato);
		arbol = nodo_nuevo;
	}else{
		int Raiz = arbol->dato;
		if(dato < Raiz){
			insertar(arbol->izquiero,dato);
		}else{
			insertar(arbol->derecho,dato);
		}
	}
	

}

void menu(){
	int datoIngresado = 0;
	int opcion = 0;
	int contador = 0;
	do{
		cout<<"Ingresa una Opcion"<<endl;
		cout<<"1- insertar nodo"<<endl;
		cout<<"2-mostrar arbol"<<endl;
		
		cin>>opcion;
		
		if(opcion == 1){
			cout<<"ingresa el numero , para el nuevo nodo que deseas ingresar: ";
			cin>>datoIngresado;
			insertar(ABB,datoIngresado);
		}else{
			mostrarArbol(ABB,contador);
		}
	}while(opcion != 2);
}



