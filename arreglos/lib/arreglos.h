#include<iostream>
#include<stdlib.h>
#include<string>
#define MAXIMO_ARRAY 11
using namespace std;

void ordenarBurbuja(int arreglo[MAXIMO_ARRAY], int tamano) {

	int indice, siguiente, temporal, valida;
	bool ordenado = false;

	do {
		valida = 0;
		for (indice = 0; indice < tamano; indice++) {
			siguiente = indice + 1;
			if (siguiente < tamano) {
				if (arreglo[indice] > arreglo[siguiente]) {
					temporal = arreglo[siguiente];
					arreglo[siguiente] = arreglo[indice];
					arreglo[indice] = temporal;
					valida++;
				}
			}
		}

		if (valida == 0) {
			ordenado = true;
		}
	} while(!ordenado);
}

void imprimirArreglo(int arreglo[MAXIMO_ARRAY], int tamano) {
	for (int indice = 0; indice < tamano; indice++) {
		cout << "pos(" << indice << ") => " << arreglo[indice] << "\n";
	}
}

int buscarEnArreglo(int arreglo[MAXIMO_ARRAY], int tamano, int busqueda){

	for (int indice = 0; indice < tamano; indice++) {
		if (arreglo[indice] == busqueda) {
			return indice;
		}
	}

	return -1;
}

void agregarDosPosiciones(int arreglo[MAXIMO_ARRAY], int nuevoArreglo[MAXIMO_ARRAY + 2], int posicion) {
	int indice, movimiento = MAXIMO_ARRAY - 1, temporal, contador = 0;
	bool seguir = true;

	for (indice = 0 ; indice < MAXIMO_ARRAY + 2; indice++) {
		if (indice < MAXIMO_ARRAY) {
			nuevoArreglo[indice] = arreglo[indice];
		} else {
			nuevoArreglo[indice] = 0;
		}
	}

	do {
		temporal = nuevoArreglo[movimiento];
		nuevoArreglo[movimiento] = 0;
		nuevoArreglo[movimiento + 1] = 0;
		nuevoArreglo[movimiento + 2]  = temporal;
		movimiento--;

		if (movimiento < posicion) {
			seguir = false;
		}
	} while(seguir);
	
}
