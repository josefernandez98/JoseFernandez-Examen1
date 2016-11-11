#include <iostream>
#include "Tablero.h"

using namespace std;

int main(int argc, char const *argv[]) {
    Tablero* instancia = new Tablero();
	instancia->llenar();
    int terminado = 0;
    int jugador = 1;
    int fila = 0;
    int columna = 0;
    do {
        instancia->imprimir();
        cout << "Jugador " << jugador << " ingrese la fila:";
        cin >> fila;
        cout << endl;
        cout << "Ingrese la columna:";
        cin >> fila;
        cout << endl;
        
        jugador++;
        if (jugador > 2) {
            jugador = 1;
        }
    } while (terminado != 1);
    return 0;
}//Fin del main
