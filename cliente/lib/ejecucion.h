#include <iostream>
using namespace std;

void pararEjecucion(bool& ejecucion){
	string orden; 
	bool ejecutar = true;

	do {
		cout << " => Desea terminar el programa (S/N): \n";
		cin >> orden;

		if (orden == "S" || orden == "N") {
			if (orden == "S") {
				ejecucion = false;
			}

			ejecutar = false;
		} else {
			cout << "Escriba S si desea continuar o escriba N si desea parar \n";
		}

	} while(ejecutar);

}

void inicarEjecucion()
{
	cout << "========================================== \n";
	cout << "           Programa iniciado               \n";
	cout << "========================================== \n";
}

void terminarEjecucion(int clientes, double monto)
{
	cout << "========================================== \n";
	cout << "           Programa finalizado             \n";
	cout << "La cantidad de clientes es : " << clientes << "\n";
	cout << "El monto total es de : " << monto << "\n";
	cout << "========================================== \n";
}
