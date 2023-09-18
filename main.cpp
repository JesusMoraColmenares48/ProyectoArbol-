#include "Reader.h"
#include "arbol.h"

int main(){
	Reader reader;
	vector<vector<string>> lines = reader.read();
	// cout << lines[0][0] << endl;
	// menu();
	int contador=0;
	for(int i=0; i< lines[1].size(); i++){
		insertar(ABB,lines[1][i]);
	}
	mostrarArbol(ABB, contador);

}
