#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;

double obtenerDoble(string entrada){
	return strtod(entrada.c_str(), NULL);
}

int obtenerEntero(string entrada)
{
	return atoi(entrada.c_str());
}

string obtenerCadena(string entrada){
	return entrada;
}

string obtenerEntrada(string mensaje) {
	string entrada;
	cout << mensaje << "\n";
	cin >> entrada;
	return entrada;	
}

void imprimir(string mensaje){
	cout << mensaje << "\n";
}


