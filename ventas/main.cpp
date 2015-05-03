#include<iostream>
#include <string.h>
#include "lib/utiles.h"
#include "lib/ventas.h"
using namespace std;

int main()
{
	int maximo = obtenerDimension(), opcion, cantidad;
	int contadores[3] = {0, 0, 0};
	double monto, montoReal, montoTotal;
    double ventas[3][9999];
	bool seguir = true;

	imprimir("--------- Programa ventas -----------");
	imprimir("");
	imprimir("Las ventas son : ");
	imprimir("Ventas al contado opcion (1)");
	imprimir("Ventas con plazo menor a 10 meses opcion (2)");
	imprimir("Ventas con plazo mayor igual a 10 meses (3)");
	imprimir("Si desea parar el programa ingrese (0)");
	imprimir("");

	do {
		opcion = obtenerEntero(obtenerEntrada("Ingrese la opcion"));

		if (opcion == 1 || opcion == 2 || opcion == 3) {
			--opcion;
			monto = obtenerMonto();
			cantidad = obtenerCantidad();
			montoReal = componerMonto(opcion, monto, cantidad);

			if (contadores[opcion] < maximo) {
				imprimir("");
				imprimir("Agregando venta ... ");
				procesarContadores(opcion, contadores);
				agregarVentasGenerales(ventas, opcion, contadores[opcion], montoReal);	
			} else {
				imprimir("");
				imprimir("Las ventas ya superaron el maximo ...");
			}			
		} else {
			imprimir("--------- Fin del programa -----------");
			imprimir("");
			seguir = false;
		}
	} while(seguir);

	imprimir("--------- Resumen de ventas -----------");
	imprimir("");

	for (int indice = 0; indice < 3; indice ++) {
		montoTotal = obtenerMontoTotal(ventas, indice, contadores[indice]);		
		imprimirVentas(obtenerMensajeTotal(indice), contadores[indice], montoTotal);	
	}

	return 1;
}
