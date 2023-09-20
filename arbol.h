// #include <conio.h>
#include "Reader.h"
#include <iostream>
#include <stdlib.h>
using namespace std;


struct Nodo{
	string dato;
	Nodo *derecho;
	Nodo *izquiero;
	int numHojas;
	vector<string> DatoDeHojas;
	bool Balanceado = false;

};
int numeroHojas=0;
vector<string> Hojas;

//metodo utilizado para poder determinar el numero de niveles y asi con el Metodo ArbolBalanceado determinar si el arbol esta balanceado o no
int ContarNiveles(Nodo *arbol) {
    if (arbol == NULL)
        return 0;
    return max(ContarNiveles(arbol->izquiero), ContarNiveles(arbol->derecho)) + 1;
}

//metodo utilizado para determinar la diferencia de niveles entre la rama izquierda y derecha y asi determinar si el arbol esta balanceado o no
bool ArbolBlanceado(Nodo* arbol) {
    if (arbol == NULL)
        return true;

    int AlturaRamaIzquierda = ContarNiveles(arbol->izquiero);
    int AlturaRamaDerecha = ContarNiveles(arbol->derecho);

    if (abs(AlturaRamaIzquierda - AlturaRamaDerecha) <= 1 && ArbolBlanceado(arbol->izquiero) && ArbolBlanceado(arbol->derecho))
        return true;

    return false;
}

//metodo utilizado pàra poder contar la altura de cada arbol , midiendo la latura de la rama izquierda y derecha y determinar cual es mayor y asi saber que altura tiene
int calcularAltura(Nodo *arbol){
	if(arbol==NULL){
		return 0 ;
	}else{
		int alturaizquierda = calcularAltura(arbol->izquiero);
		int alturaDerecha = calcularAltura(arbol->derecho);
		
		return max(alturaizquierda, alturaDerecha)+1;
	}
}



//metodo utilizado para imprimir por pantalla los arboles mediante recursividad
void mostrarArbol(Nodo *arbol, int contador){
	
	if(arbol == NULL){
		return;
	}else{
		contador++;
		mostrarArbol(arbol->derecho,contador);
		for(int i = 0; i < contador; i++){
			cout<< "   ";
		}
		contador++;
		cout<<arbol->dato<<endl;
		mostrarArbol(arbol->izquiero, contador);
	}
}

//metodo utilizado para inicializar los nodos de los arboles, los cuales contendran un string como dato , un hijo izquierdo y un hijo derecho
Nodo *crearNodo(string Dato){
	Nodo *nodo=new Nodo();	
	nodo->dato=Dato;
	nodo->derecho=NULL;
	nodo->izquiero=NULL;
	
	return nodo;
}



Nodo *ABB = NULL;


//metodo para poder agregar nuevos nodos al arbol , determinando si deben ponerse a la izquierda o a la derecha
void insertar(Nodo *&arbol, string dato){
	
	if(arbol == NULL){
		Nodo *nodo_nuevo = crearNodo(dato);
		arbol = nodo_nuevo;
	}else{
		string raiz = arbol->dato;
		Reader reader;
		bool dato_menor = reader.isAlphabeticallySmaller(dato,raiz);
		if(dato_menor==true){
			insertar(arbol->izquiero,dato);
		}else{
			insertar(arbol->derecho,dato);
		}
	}
	

}

//metodo para hacer el recorrido post orden y determinar el numero de hojas de cada dato revisando si cada nodo tiene hijos o no
void RecorerPostOrden(Nodo *arbol){
	if(arbol == NULL){
		return;
	}
	else{
		RecorerPostOrden(arbol->izquiero);
		RecorerPostOrden(arbol->derecho);
		cout<<arbol->dato<<" - ";
	
		
		if(arbol->izquiero == NULL && arbol->derecho == NULL){
			Hojas.push_back(arbol->dato);			
			numeroHojas++;
		}		
	}
}


