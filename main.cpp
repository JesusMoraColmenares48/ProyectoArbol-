#include "Reader.h"
#include "arbol.h"

/*
	Realizado por:
	Jesus Miguel Mora Colmenares CI-30351836
	Andres Augusto Gutierrez CI-30617004
*/


int ContadorDeArboles = 0;
//vector que se usara para almacenar los arboles generados desde el archivo de texto
vector <Nodo*> Arboles;
int contador=0;


void MostrarAltura(){
	for(int i = 0; i < ContadorDeArboles; i++){
		cout<<"Altura del arbol "<<(i+1)<<": ";	
		cout<<calcularAltura(Arboles[i])<<endl;
	}
}

//este metodo se encargara de recorrer el vector de arboles que tenemos para mandarlo al metodo que se encargara de determinar si esta balanceado o no el arbol
void determinarBalanceoDeArboles(){
	for(int i = 0; i < ContadorDeArboles; i++){
		if(ArbolBlanceado(Arboles[i])){
			Arboles[i]->Balanceado = true;
		}
	}	
}


//metodo para imprimir por pantalla cuales arboles estan balanceados
void mostrarBalanceoDeArboles(){
	determinarBalanceoDeArboles();
	for(int i = 0; i < ContadorDeArboles; i++){
		if(Arboles[i]->Balanceado){
			cout<<"El arbol "<<(i+1)<<" esta balanceado"<<endl;			
		}else{
			cout<<"El arbol "<<(i+1)<<" esta desbalanceado"<<endl;
		}
	}
}


//metodo para imprimir por pantalla los arboles
void MostrarArboles(){
	for(int i = 0; i < ContadorDeArboles; i++){
		mostrarArbol(Arboles[i],contador);
		cout<<'\n'<<endl;
	}	
}

/*metodo para imprimir por pantalla el recorrido postOrden llamando al metodo que generara el post orden llamado RecorerPostOrden
este metodo ademas obtiene el numero de hojas que se calcula en el post orden con la variable llamada numeroHojas
y se lo asigna al atributo del arbol llamado numHojas, y luego con la ayuda del vector Hojas que esta en arbol.h le vamos asignar el valor que contiene
cada hoja al vector datoDeHojas que es parte del struct Nodo y posterorimente limpliamos el vector hojas ya que va a estar constantemente cargando los datos 
de las hojas de todos los arboles*/

void RecorridosPosOrden(){
	for(int i = 0; i < ContadorDeArboles; i++){
		cout<<"Recorrido PosOrden del Arbol "<<(i+1)<<" :";
		RecorerPostOrden(Arboles[i]);
		cout<<'\n'<<endl;
		Arboles[i]->numHojas = numeroHojas;
		Arboles[i]->DatoDeHojas = Hojas;
		Hojas.clear();
		numeroHojas = 0;
		
	}	
}

//metodo para imprimir por pantalla el numero de hojas de cada arbol junto al dato que contiene cada hoja
void MostrarHojasDeLosArboles(){
	for(int i = 0; i < ContadorDeArboles; i++){
		cout<<"Hojas del Arbol "<<(i+1)<<" :";	
		cout<<Arboles[i]->numHojas<<" ->";
		for(int j = 0; j < Arboles[i]->numHojas; j++){
			cout<<Arboles[i]->DatoDeHojas[j]<<" - ";
		}
		cout<<endl;
			
	}	
}

int main(){
	Reader reader;
	int opcion = 0;
	vector<vector<string>> lines = reader.read();
			
		for(int i = 0; i < lines.size() ; i++){		
			for(int j=0; j< lines[i].size(); j++){
				insertar(ABB,lines[i][j]);		
			}		
			Arboles.push_back(ABB);
			ContadorDeArboles++;
			ABB = NULL;
		}
		
	//llamando metodos para imprimir datos por pantalla
	cout<<"||||ARBOLES GENERADOS|||"<<endl;
	MostrarArboles();
	cout<<'\n'<<endl;
	cout<<"||||POSTORDEN|||"<<endl;
	RecorridosPosOrden();
	cout<<'\n'<<endl;
	
	cout<<"||||HOJAS|||"<<endl;
	MostrarHojasDeLosArboles();
	cout<<'\n'<<endl;
	
	cout<<"||||BALANCEO|||"<<endl;
	mostrarBalanceoDeArboles();
	cout<<'\n'<<endl;
	
	cout<<"||||ALTURA|||"<<endl;
	MostrarAltura();
}
