#include<iostream>
#include<stdlib.h>
#include<string>
#include <sstream>

using namespace std;

struct Fecha {
	int dia;
	int mes;
	int ano;
};

struct Atencion {
	Fecha fecha;
	string detalle;
};

struct Paciente{
	int codigo;
	string nombre;
	string apellido;
	string genero;
	Fecha nacimiento;
	Fecha admision;
	int atencionTotal;
	Atencion * atenciones;
};

int obtenerDimension() {
	int tamano;
	bool seguir = true;

	do {
		tamano = obtenerEntero(obtenerEntrada("Ingresa el tamano del arreglo"));

		if (tamano == 0) {
			imprimir("El tamano debe ser mayor a 0");
		} else {
			seguir = false;
		}
	} while(seguir);

	return tamano;
}

int obtenerCodigo() {
	int tamano;
	bool seguir = true;

	do {
		tamano = obtenerEntero(obtenerEntrada("Ingresa el codigo del paciente"));

		if (tamano == 0) {
			imprimir("El codigo debe ser mayor a cero... ");
		} else {
			seguir = false;
		}
	} while(seguir);

	return tamano;
}

void mostrarPaciente(Paciente paciente) {	
	string genero = "masculino";

	if (paciente.genero == "f") {
		genero = "femenino";
	}

	cout << "El codigo del paciente es : " << paciente.codigo << " \n";
	cout << "El nombre del paciente es : " << paciente.nombre << " \n";	
	cout << "El apellido del paciente es : " << paciente.apellido << " \n";
	cout << "El genero del paciente es : " << genero << " \n";
}

void mostrarFecha(Fecha fecha) {
	cout << fecha.ano << "/" << fecha.mes << "/" << fecha.dia << " \n";
}

void mostrarAtencion(Atencion atencion) {
	cout << "Atencion : " << atencion.detalle << " (" 
		 << atencion.fecha.ano << "/" << atencion.fecha.mes << "/" 
		 << atencion.fecha.dia << " ) \n";
}

Paciente agregarPaciente()
{
	Paciente paciente;
	Fecha nacimiento;
	Fecha admision;
	Atencion * atenciones = NULL;
	int tamano = 0, contador = 0; 
	bool seguir = true;

	paciente.codigo = obtenerEntero(obtenerEntrada("Ingrese codigo de paciente"));
	paciente.nombre = obtenerCadena(obtenerEntrada("Ingrese nombre de paciente"));
	paciente.apellido = obtenerCadena(obtenerEntrada("Ingrese apellido de paciente"));
	paciente.genero = obtenerCadena(obtenerEntrada("Ingrese genere (m / f)"));
	nacimiento.dia = obtenerEntero(obtenerEntrada("Ingrese dia de nacimiento"));
	nacimiento.mes = obtenerEntero(obtenerEntrada("Ingrese mes de nacimiento"));
	nacimiento.ano = obtenerEntero(obtenerEntrada("Ingrese ano de nacimiento"));
	paciente.nacimiento = nacimiento;
	admision.dia = obtenerEntero(obtenerEntrada("Ingrese dia de admision"));
	admision.mes = obtenerEntero(obtenerEntrada("Ingrese mes de admision"));
	admision.ano = obtenerEntero(obtenerEntrada("Ingrese ano de admision"));
	paciente.admision = admision;
	imprimir(" === Agregando atenciones ===> ");
	tamano = obtenerDimension();
	atenciones = new Atencion[tamano];
	paciente.atencionTotal = tamano;

	do {
		imprimir("====== Ingrese los datos de la atencion ======");
		Atencion atencion;
		Fecha fechaatencion;
		atencion.detalle = obtenerCadena(obtenerEntrada("Ingrese detalle de la atencion"));
		fechaatencion.dia = obtenerEntero(obtenerEntrada("Ingrese dia de atencion"));
		fechaatencion.mes = obtenerEntero(obtenerEntrada("Ingrese mes de atencion"));
		fechaatencion.ano = obtenerEntero(obtenerEntrada("Ingrese ano de atencion"));
		atencion.fecha = fechaatencion;
		atenciones[contador] = atencion;
		contador++;

		if (contador == tamano) {
			seguir = false;
		}
	} while(seguir);

	paciente.atenciones = atenciones;
	
	return paciente;
}


