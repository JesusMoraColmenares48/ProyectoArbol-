#include "Reader.h"
#include "arbol.h"

int main(){
	Reader reader;
	vector<vector<string>> lines = reader.read();
	cout << lines[0][0] << endl;
	// Menu();

}
