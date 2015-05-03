#include<iostream>
#include <string.h>
#include "lib/utiles.h"
#include "lib/arreglos.h"
using namespace std;

int main()
{
	bool seguir = true;
	int indice;
	int arreglo[MAXIMO_ARRAY] = {5, 9, 2, 1, 10, 55, 3, 7, 6, 4, 8};
	int nuevoArreglo[MAXIMO_ARRAY + 2];
	imprimir("------------ Ordenamiento Burbuja ------------");
	imprimir("");
	imprimir("Arreglo inicial desordenado : ");
	imprimir("");
	imprimirArreglo(arreglo, MAXIMO_ARRAY);
	imprimir("Arreglo ordenado con burbuja : ");
	imprimir("");
	ordenarBurbuja(arreglo, MAXIMO_ARRAY);
	imprimirArreglo(arreglo, MAXIMO_ARRAY);

	imprimir("");
	imprimir("------------ Busqueda binaria ------------");

	do {
		indice = buscarEnArreglo(arreglo, MAXIMO_ARRAY, obtenerEntero(obtenerEntrada("Ingrese valor para buscar : ")));

		if (indice == -1) {
			imprimir("No existe el elemento ingresado ...");
		} else {
			seguir = false;
		}
	} while(seguir);

	imprimir("");
	imprimir("------------ Valor encontrado ------------");
	agregarDosPosiciones(arreglo, nuevoArreglo, indice);
	imprimir("");
	imprimir("Arreglo con elemento desplazado 2 posiciones : ");
	imprimir("");
	imprimirArreglo(nuevoArreglo, MAXIMO_ARRAY + 2);

	return 1;
}
