#include<iostream>
#include<stdlib.h>
#include<string>
#include <sstream>

using namespace std;

int obtenerDimension() {
	int tamano;
	bool seguir = true;

	do {
		tamano = obtenerEntero(obtenerEntrada("Ingresa la dimension del arreglo"));

		if (tamano == 0 || tamano > 9999) {
			imprimir("La dimension del arreglo debe ser mayor a 0 y menor a 9999 ... ");
		} else {
			seguir = false;
		}
	} while(seguir);

	return tamano;
}

int obtenerCantidad() {
	int tamano;
	bool seguir = true;

	do {
		tamano = obtenerEntero(obtenerEntrada("Ingresa la cantidad vendida"));

		if (tamano == 0) {
			imprimir("La cantidad de venta debe ser mayor a 0 ... ");
		} else {
			seguir = false;
		}
	} while(seguir);

	return tamano;
}

double obtenerMonto() {
	double monto;
	bool seguir = true;

	do {
		monto = obtenerDoble(obtenerEntrada("Ingresa el monto vendido"));

		if (monto == 0) {
			imprimir("El monto vendido debe ser mayor a 0 ... ");
		} else {
			seguir = false;
		}
	} while(seguir);

	return monto;
}


void agregarVentasGenerales(double ventas[3][9999], int opcion, int posicion, double monto) {
	ventas[opcion][posicion] = monto;
}

double componerMonto(int opcion, double monto, int cantidad) {
	double total = cantidad * monto;

	switch(opcion) {
		case 0:
			return total;
		case 1:
			return total + (total * 0.35);
		case 2:
			return total + (total * 0.5);		
	}

	return total;
}

string obtenerMensajeTotal(int opcion){
	string mensaje = "-";

	switch(opcion) {
		case 0:
			mensaje = "Clientes con ventas al contado : ";
			break;
		case 1:
			mensaje = "Clientes con plazo menor a 10 meses : ";
			break;
		case 2:
			mensaje = "Clientes con plazo mayor igual a 10 meses : ";
			break;
	}

	return mensaje;
}

double obtenerMontoTotal(double ventas[3][9999], int opcion, int maximo) {
	double monto = 0.0;

	for (int indice = 0; indice <= maximo; indice++) {
		monto += ventas[opcion][indice];
	}

	return monto;
}

void procesarContadores(int opcion, int (&contadores)[3]) {
	contadores[opcion]++;
}

void imprimirVentas(string mensaje, int total, double monto) {
	stringstream  output;
	output << mensaje << total << " con un monto de S./" << monto << "\n";
	cout << output.str();
}


