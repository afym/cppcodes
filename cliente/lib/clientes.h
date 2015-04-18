#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

string leerCliente(){
	string cliente;
	bool ejecutar = true;

	do{
		cout << "Ingrese el nombre del cliente : \n";
		cin >> cliente;

		if (cliente.size() < 3) {
			cout << "Nombre incorreco el nombre debe tener mas de 3 caracteres \n";
		} else {
			ejecutar = false;
		}
	} while(ejecutar);

	return cliente;
}

double leerMonto()
{
	char * entrada;
	double monto;
	bool ejecutar = true;

	do {
		cout << "Ingrese el monto total de compra : \n";
		cin >> entrada;
		// Validando entradas de datos para caracteres
		monto = strtod(entrada, NULL);
		if (monto > 0) {
			ejecutar = false;
		} else {
			cout << "Monto incorreco ... el monto debe ser mayor que 0 \n";
		}
	} while(ejecutar);

	return monto;
}

void agregarCliente(int& cliente)
{
	cliente += 1;
}

void incrementarMonto(double entrada, double& monto)
{
	monto += entrada;
}
