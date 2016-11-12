#include <iostream>
#include "Tablero.h"

using namespace std;

int main(int argc, char const *argv[]) {
    Tablero* instancia = new Tablero();
	instancia->llenar();
    int terminado = 0;
    int jugador = 1;
    int fila_Actual = 0;
    int columna_Actual = 0;
    int fila = 0;
    int columna = 0;
    int espacios = 0;
    do {
        instancia->imprimir();
        cout << "Jugador " << jugador << ", ingrese la fila en la que esta su pieza:";
        cin >> fila_Actual;
        fila_Actual = instancia->verificacionFila(fila_Actual);
        cout << endl;
        cout << "Ingrese la columna en la que esta su pieza:";
        cin >> columna_Actual;
        cout << endl;
        columna_Actual = instancia->verificacionColumna(columna_Actual, fila_Actual, jugador);
        instancia->movimiento(fila_Actual, columna_Actual, jugador);
        terminado = instancia->verificarMatriz();
        jugador++;
        if (jugador > 2) {
            jugador = 1;
        }
    } while ((terminado != 1) || (terminado != 2) || (terminado != 121));
    if (terminado == 1) {
        cout << "Gano el jugador 2." << endl;
    }
    if (terminado == 2) {
        cout << "Gano el jugador 1." << endl;
    }
    if (terminado == 121) {
        cout << "Empate!!" << endl; 
    }
    return 0;
}//Fin del main
