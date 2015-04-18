// Autor : Angel Francisco Ybarhuen Manrique
// Programa : Clientes y montos
// Fecha : 04/2015
#include <iostream>
#include "lib/clientes.h"
#include "lib/ejecucion.h"

using namespace std;

int main()
{
	int clientes = 0;
	double monto = 0.0;
	bool ejecutar = true;

	inicarEjecucion();

	do {
		string entradaDeCliente = leerCliente();
		double entradaDemonto = leerMonto();

		agregarCliente(clientes);
		incrementarMonto(entradaDemonto, monto);
		pararEjecucion(ejecutar);
	} while(ejecutar);

	terminarEjecucion(clientes, monto);
}
