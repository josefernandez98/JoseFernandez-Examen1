#include <iostream>
#include "Tablero.h"
using namespace std;

Tablero::Tablero() {
    matriz = new char*[11];
    for (int i = 0; i < 11; i++) {
        matriz[i] = new char[11];
    }
}

Tablero::~Tablero() {
    for (int i = 0; i < 11; ++i) {
        delete[] matriz[i];
        matriz[i] = NULL;
    }
    delete[] matriz;
    cout << "Terminando..." << endl;
}

void Tablero::movimiento(int fila, int columna) {

}




//NO TOCAR
void Tablero::imprimir() {
    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 11; j++) {
            cout << '[' << matriz[i][j] << ']';
        }
        cout << endl;
    }
}
void Tablero::llenar() {
    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 11; j++) {
            if ((i == 0 && j == 0) || (i == 10 && j == 10)) {
                matriz[i][j] = '+';
            } else if ((i == 0 && j == 10) || (i == 10 && j == 0)) {
                matriz[i][j] = '#';
            } else {
                matriz[i][j] = '-';
            }
        }//Fin del for
    }//Fin del for
} //Fin del metodo
