#include<iostream>
#include<stdlib.h>
#include "lib/utiles.h"
#include "lib/pacientes.h"

using namespace std;

int main(){
	int tamano = obtenerDimension(), contador = 0;
	bool seguir = true;
	Paciente * pacientes = new Paciente[tamano] ;
	
	do {
		
		imprimir("====== Ingrese los datos del paciente ======");
		Paciente paciente = agregarPaciente();
		pacientes[contador] = paciente;
		contador++;

		if (contador == tamano) {
			seguir = false;
		}
	} while(seguir);

	for (int indice = 0; indice < tamano; indice++) {
		mostrarPaciente(pacientes[indice]);
		imprimir("Fecha de nacimiento : ");
		mostrarFecha(pacientes[indice].nacimiento);
		imprimir("Fecha de admision : ");
		mostrarFecha(pacientes[indice].admision);
		
		imprimir("Mostrando atenciones : ");
		Atencion * atenciones = pacientes[indice].atenciones;

		for (int ia = 0; ia < pacientes[indice].atencionTotal; ia++) {
			mostrarAtencion(atenciones[ia]);
		}
	}

	return 1;
}      
