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

void Tablero::movimiento(int fila, int columna, int filaActual, int columnaActual, int jugador) {
    int espacios = 0;
    if (jugador == 1) {
        cout << "Cuantos espacios se quiere mover (1 o 2):";
        cin >> espacios;
        if (espacios <= 0 || espacios > 2) {
            do {
                cout << "Valor invalido." << endl;
                cout << "Cuantos espacios se quiere mover (1 o 2):";
                cin >> espacios;
            } while (espacios <= 0 || espacios > 2);
        }//Fin del verificador
    }
    if (jugador == 2) {

    }
}//Fin del metodo

//NO TOCAR
void Tablero::imprimir() {
    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 11; j++) {
            cout << '[' << matriz[i][j] << ']';
        }
        cout << endl;
    }
}

int Tablero::verificacionFila(int fila) {
    if (fila > 10 || fila < 0) {
        do {
            cout << "No ingreso un valor valido." << endl;
            cout << "Ingrese la fila en la que esta su pieza:";
            cin >> fila;
            cout << endl;
        } while (fila > 10 || fila < 0);
    }//Fin del if
    return fila;
}


int Tablero::verificacionColumna(int columna, int fila, int jugador) {
    if (columna > 10 || columna < 0) {
        do {
            cout << "No ingreso un valor valido." << endl;
            cout << "Ingrese la columna en la que esta su pieza:";
            cin >> columna;
            cout << endl;
        } while (columna > 10 || columna < 0);
    }
    if (jugador == 1) {
        if ((matriz[fila][columna] == '#') || (matriz[fila][columna] == ' ')) {
            do {
                cout << "No ingreso un valor valido." << endl;
                cout << "Ingrese la columna en la que esta su pieza:";
                cin >> columna;
                cout << endl;
            } while ((matriz[fila][columna] == '#') || (matriz[fila][columna] == ' '));
        }//Fin del if
    }//Fin del if
    if (jugador == 2) {
        if ((matriz[fila][columna] == '+') || (matriz[fila][columna] == ' ')) {
            do {
                cout << "No ingreso un valor valido." << endl;
                cout << "Ingrese la columna en la que esta su pieza:";
                cin >> columna;
                cout << endl;
            } while ((matriz[fila][columna] == '+') || (matriz[fila][columna] == ' '));
        }//Fin del if
    }
    return columna;
}

void Tablero::llenar() {
    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 11; j++) {
            if ((i == 0 && j == 0) || (i == 10 && j == 10)) {
                matriz[i][j] = '+';
            } else if ((i == 0 && j == 10) || (i == 10 && j == 0)) {
                matriz[i][j] = '#';
            } else {
                matriz[i][j] = ' ';
            }
        }//Fin del for
    }//Fin del for
} //Fin del metodo
