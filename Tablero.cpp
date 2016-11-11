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

void Tablero::movimiento(int filaActual, int columnaActual, int jugador) {
    int espacios = 0;
    int direccion = 0;
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
        cout << "Arriba: 1" << endl;
        cout << "Abajo: 2" << endl;
        cout << "Izquierda: 3" << endl;
        cout << "Derecha: 4" << endl;
        cout << "Diagonal Izquierda Arriba: 5" << endl;
        cout << "Diagonal Izquierda Abajo: 6" << endl;
        cout << "Diagonal Derecha Arriba: 7" << endl;
        cout << "Diagonal Derecha Abajo: 8" << endl;
        cout << "Ingrese su direccion: ";
        cin >> direccion;
        cout << endl;
        if (direccion == 1) {
            if (filaActual - espacios < 0) {
                cout << "Posicion invalida, pierde su turno." << endl;
            } else {
                if (espacios == 1) {
                    filaActual-=1;
                    if (matriz[filaActual][columnaActual] == ' ') {
                        filaActual++;
                        filaActual-=espacios;
                        matriz[filaActual][columnaActual] = '+';
                        //Arriba
                        if (filaActual - 1 >= 0) {
                            if (matriz[filaActual-1][columnaActual] == '#') {
                                matriz[filaActual-1][columnaActual] = '+';
                            }
                        }
                        //abajo
                        if (filaActual + 1 <= 10) {
                            if (matriz[filaActual+1][columnaActual] == '#') {
                                matriz[filaActual+1][columnaActual] = '+';
                            }
                        }
                        //Izquierda
                        if (columnaActual - 1 >= 0) {
                            if (matriz[filaActual][columnaActual-1] == '#') {
                                matriz[filaActual][columnaActual-1] = '+';
                            }
                        }
                        //Derecha
                        if (columnaActual + 1 <= 10) {
                            if (matriz[filaActual][columnaActual+1] == '#') {
                                matriz[filaActual][columnaActual+1] = '+';
                            }
                        }
                        //Diagonal Izquierda Arriba
                        if ((filaActual - 1 >= 0) && (columnaActual - 1 >= 0)) {
                            if (matriz[filaActual-1][columnaActual - 1] == '#') {
                                matriz[filaActual-1][columnaActual - 1] = '+';
                            }
                        }
                        //Diagonal Izquierda Abajo
                        if ((filaActual + 1 <= 10) && (columnaActual - 1 >= 0)) {
                            if (matriz[filaActual+1][columnaActual - 1] == '#') {
                                matriz[filaActual+1][columnaActual - 1] = '+';
                            }
                        }
                        //Diagonal Derecha Arriba
                        if ((filaActual - 1 >= 0) && (columnaActual + 1 <= 10)) {
                            if (matriz[filaActual-1][columnaActual + 1] == '#') {
                                matriz[filaActual-1][columnaActual + 1] = '+';
                            }
                        }
                        //Diagonal Derecha Abajo
                        if ((filaActual + 1 < 10) && (columnaActual + 1 <= 10)) {
                            if (matriz[filaActual + 1][columnaActual + 1] == '#') {
                                matriz[filaActual + 1][columnaActual + 1] = '+';
                            }
                        }
                    } else {
                        cout << "No puede saltar piezas. Turno perdido." << endl;
                    }
                }
                if (espacios == 2) {
                    filaActual-=2;
                    if (matriz[filaActual][columnaActual] == ' ') {
                        filaActual+=2;
                        filaActual-=espacios;
                        matriz[filaActual][columnaActual] = '+';
                        //Arriba
                        if (filaActual - 1 >= 0) {
                            if (matriz[filaActual-1][columnaActual] == '#') {
                                matriz[filaActual-1][columnaActual] = '+';
                            }
                        }
                        //abajo
                        if (filaActual + 1 <= 10) {
                            if (matriz[filaActual+1][columnaActual] == '#') {
                                matriz[filaActual+1][columnaActual] = '+';
                            }
                        }
                        //Izquierda
                        if (columnaActual - 1 >= 0) {
                            if (matriz[filaActual][columnaActual-1] == '#') {
                                matriz[filaActual][columnaActual-1] = '+';
                            }
                        }
                        //Derecha
                        if (columnaActual + 1 <= 10) {
                            if (matriz[filaActual][columnaActual+1] == '#') {
                                matriz[filaActual][columnaActual+1] = '+';
                            }
                        }
                        //Diagonal Izquierda Arriba
                        if ((filaActual - 1 >= 0) && (columnaActual - 1 >= 0)) {
                            if (matriz[filaActual-1][columnaActual - 1] == '#') {
                                matriz[filaActual-1][columnaActual - 1] = '+';
                            }
                        }
                        //Diagonal Izquierda Abajo
                        if ((filaActual + 1 <= 10) && (columnaActual - 1 >= 0)) {
                            if (matriz[filaActual+1][columnaActual - 1] == '#') {
                                matriz[filaActual+1][columnaActual - 1] = '+';
                            }
                        }
                        //Diagonal Derecha Arriba
                        if ((filaActual - 1 >= 0) && (columnaActual + 1 <= 10)) {
                            if (matriz[filaActual-1][columnaActual + 1] == '#') {
                                matriz[filaActual-1][columnaActual + 1] = '+';
                            }
                        }
                        //Diagonal Derecha Abajo
                        if ((filaActual + 1 < 10) && (columnaActual + 1 <= 10)) {
                            if (matriz[filaActual + 1][columnaActual + 1] == '#') {
                                matriz[filaActual + 1][columnaActual + 1] = '+';
                            }
                        }
                    } else {
                        cout << "No puede saltar piezas. Turno perdido." << endl;
                    }
                }
            }//Fin del else
        }//FIn del if direccion
        if (direccion == 2) {
            if (filaActual + espacios > 10) {
                cout << "Posicion invalida, pierde su turno." << endl;
            } else {
                if (espacios == 1) {
                    filaActual+=1;
                    if (matriz[filaActual][columnaActual] == ' ') {
                        filaActual--;
                        filaActual+=espacios;
                        matriz[filaActual][columnaActual] = '+';
                        //Arriba
                        if (filaActual - 1 >= 0) {
                            if (matriz[filaActual-1][columnaActual] == '#') {
                                matriz[filaActual-1][columnaActual] = '+';
                            }
                        }
                        //abajo
                        if (filaActual + 1 <= 10) {
                            if (matriz[filaActual+1][columnaActual] == '#') {
                                matriz[filaActual+1][columnaActual] = '+';
                            }
                        }
                        //Izquierda
                        if (columnaActual - 1 >= 0) {
                            if (matriz[filaActual][columnaActual-1] == '#') {
                                matriz[filaActual][columnaActual-1] = '+';
                            }
                        }
                        //Derecha
                        if (columnaActual + 1 <= 10) {
                            if (matriz[filaActual][columnaActual+1] == '#') {
                                matriz[filaActual][columnaActual+1] = '+';
                            }
                        }
                        //Diagonal Izquierda Arriba
                        if ((filaActual - 1 >= 0) && (columnaActual - 1 >= 0)) {
                            if (matriz[filaActual-1][columnaActual - 1] == '#') {
                                matriz[filaActual-1][columnaActual - 1] = '+';
                            }
                        }
                        //Diagonal Izquierda Abajo
                        if ((filaActual + 1 <= 10) && (columnaActual - 1 >= 0)) {
                            if (matriz[filaActual+1][columnaActual - 1] == '#') {
                                matriz[filaActual+1][columnaActual - 1] = '+';
                            }
                        }
                        //Diagonal Derecha Arriba
                        if ((filaActual - 1 >= 0) && (columnaActual + 1 <= 10)) {
                            if (matriz[filaActual-1][columnaActual + 1] == '#') {
                                matriz[filaActual-1][columnaActual + 1] = '+';
                            }
                        }
                        //Diagonal Derecha Abajo
                        if ((filaActual + 1 < 10) && (columnaActual + 1 <= 10)) {
                            if (matriz[filaActual + 1][columnaActual + 1] == '#') {
                                matriz[filaActual + 1][columnaActual + 1] = '+';
                            }
                        }
                    } else {
                        cout << "No puede saltar piezas. Turno perdido." << endl;
                    }
                }
                if (espacios == 2) {
                    filaActual+=2;
                    if (matriz[filaActual][columnaActual] == ' ') {
                        filaActual-=2;
                        filaActual+=espacios;
                        matriz[filaActual][columnaActual] = '+';
                        //Arriba
                        if (filaActual - 1 >= 0) {
                            if (matriz[filaActual-1][columnaActual] == '#') {
                                matriz[filaActual-1][columnaActual] = '+';
                            }
                        }
                        //abajo
                        if (filaActual + 1 <= 10) {
                            if (matriz[filaActual+1][columnaActual] == '#') {
                                matriz[filaActual+1][columnaActual] = '+';
                            }
                        }
                        //Izquierda
                        if (columnaActual - 1 >= 0) {
                            if (matriz[filaActual][columnaActual-1] == '#') {
                                matriz[filaActual][columnaActual-1] = '+';
                            }
                        }
                        //Derecha
                        if (columnaActual + 1 <= 10) {
                            if (matriz[filaActual][columnaActual+1] == '#') {
                                matriz[filaActual][columnaActual+1] = '+';
                            }
                        }
                        //Diagonal Izquierda Arriba
                        if ((filaActual - 1 >= 0) && (columnaActual - 1 >= 0)) {
                            if (matriz[filaActual-1][columnaActual - 1] == '#') {
                                matriz[filaActual-1][columnaActual - 1] = '+';
                            }
                        }
                        //Diagonal Izquierda Abajo
                        if ((filaActual + 1 <= 10) && (columnaActual - 1 >= 0)) {
                            if (matriz[filaActual+1][columnaActual - 1] == '#') {
                                matriz[filaActual+1][columnaActual - 1] = '+';
                            }
                        }
                        //Diagonal Derecha Arriba
                        if ((filaActual - 1 >= 0) && (columnaActual + 1 <= 10)) {
                            if (matriz[filaActual-1][columnaActual + 1] == '#') {
                                matriz[filaActual-1][columnaActual + 1] = '+';
                            }
                        }
                        //Diagonal Derecha Abajo
                        if ((filaActual + 1 < 10) && (columnaActual + 1 <= 10)) {
                            if (matriz[filaActual + 1][columnaActual + 1] == '#') {
                                matriz[filaActual + 1][columnaActual + 1] = '+';
                            }
                        }
                    } else {
                        cout << "No puede saltar piezas. Turno perdido." << endl;
                    }
                }
            }//Fin del else
        }//Fin de la direccion 2
        if (direccion == 3) {
            if (columnaActual - espacios < 0) {
                cout << "Posicion invalida, pierde su turno." << endl;
            } else {
                if (espacios == 1) {
                    columnaActual-=1;
                    if (matriz[filaActual][columnaActual] == ' ') {
                        columnaActual++;
                        columnaActual-=espacios;
                        matriz[filaActual][columnaActual] = '+';
                        //Arriba
                        if (filaActual - 1 >= 0) {
                            if (matriz[filaActual-1][columnaActual] == '#') {
                                matriz[filaActual-1][columnaActual] = '+';
                            }
                        }
                        //abajo
                        if (filaActual + 1 <= 10) {
                            if (matriz[filaActual+1][columnaActual] == '#') {
                                matriz[filaActual+1][columnaActual] = '+';
                            }
                        }
                        //Izquierda
                        if (columnaActual - 1 >= 0) {
                            if (matriz[filaActual][columnaActual-1] == '#') {
                                matriz[filaActual][columnaActual-1] = '+';
                            }
                        }
                        //Derecha
                        if (columnaActual + 1 <= 10) {
                            if (matriz[filaActual][columnaActual+1] == '#') {
                                matriz[filaActual][columnaActual+1] = '+';
                            }
                        }
                        //Diagonal Izquierda Arriba
                        if ((filaActual - 1 >= 0) && (columnaActual - 1 >= 0)) {
                            if (matriz[filaActual-1][columnaActual - 1] == '#') {
                                matriz[filaActual-1][columnaActual - 1] = '+';
                            }
                        }
                        //Diagonal Izquierda Abajo
                        if ((filaActual + 1 <= 10) && (columnaActual - 1 >= 0)) {
                            if (matriz[filaActual+1][columnaActual - 1] == '#') {
                                matriz[filaActual+1][columnaActual - 1] = '+';
                            }
                        }
                        //Diagonal Derecha Arriba
                        if ((filaActual - 1 >= 0) && (columnaActual + 1 <= 10)) {
                            if (matriz[filaActual-1][columnaActual + 1] == '#') {
                                matriz[filaActual-1][columnaActual + 1] = '+';
                            }
                        }
                        //Diagonal Derecha Abajo
                        if ((filaActual + 1 < 10) && (columnaActual + 1 <= 10)) {
                            if (matriz[filaActual + 1][columnaActual + 1] == '#') {
                                matriz[filaActual + 1][columnaActual + 1] = '+';
                            }
                        }
                    } else {
                        cout << "No puede saltar piezas. Turno perdido." << endl;
                    }
                }
                if (espacios == 2) {
                    columnaActual-=2;
                    if (matriz[filaActual][columnaActual] == ' ') {
                        columnaActual+=2;
                        columnaActual-=espacios;
                        matriz[filaActual][columnaActual] = '+';
                        //Arriba
                        if (filaActual - 1 >= 0) {
                            if (matriz[filaActual-1][columnaActual] == '#') {
                                matriz[filaActual-1][columnaActual] = '+';
                            }
                        }
                        //abajo
                        if (filaActual + 1 <= 10) {
                            if (matriz[filaActual+1][columnaActual] == '#') {
                                matriz[filaActual+1][columnaActual] = '+';
                            }
                        }
                        //Izquierda
                        if (columnaActual - 1 >= 0) {
                            if (matriz[filaActual][columnaActual-1] == '#') {
                                matriz[filaActual][columnaActual-1] = '+';
                            }
                        }
                        //Derecha
                        if (columnaActual + 1 <= 10) {
                            if (matriz[filaActual][columnaActual+1] == '#') {
                                matriz[filaActual][columnaActual+1] = '+';
                            }
                        }
                        //Diagonal Izquierda Arriba
                        if ((filaActual - 1 >= 0) && (columnaActual - 1 >= 0)) {
                            if (matriz[filaActual-1][columnaActual - 1] == '#') {
                                matriz[filaActual-1][columnaActual - 1] = '+';
                            }
                        }
                        //Diagonal Izquierda Abajo
                        if ((filaActual + 1 <= 10) && (columnaActual - 1 >= 0)) {
                            if (matriz[filaActual+1][columnaActual - 1] == '#') {
                                matriz[filaActual+1][columnaActual - 1] = '+';
                            }
                        }
                        //Diagonal Derecha Arriba
                        if ((filaActual - 1 >= 0) && (columnaActual + 1 <= 10)) {
                            if (matriz[filaActual-1][columnaActual + 1] == '#') {
                                matriz[filaActual-1][columnaActual + 1] = '+';
                            }
                        }
                        //Diagonal Derecha Abajo
                        if ((filaActual + 1 < 10) && (columnaActual + 1 <= 10)) {
                            if (matriz[filaActual + 1][columnaActual + 1] == '#') {
                                matriz[filaActual + 1][columnaActual + 1] = '+';
                            }
                        }
                    } else {
                        cout << "No puede saltar piezas. Turno perdido." << endl;
                    }
                }
            }//Fin del else
        }//Fin del if direccion 3
        if (direccion == 4) {
            if (columnaActual + espacios > 10) {
                cout << "Posicion invalida, pierde su turno." << endl;
            } else {
                if (espacios == 1) {
                    columnaActual+=1;
                    if (matriz[filaActual][columnaActual] == ' ') {
                        columnaActual--;
                        columnaActual+=espacios;
                        matriz[filaActual][columnaActual] = '+';
                        //Arriba
                        if (filaActual - 1 >= 0) {
                            if (matriz[filaActual-1][columnaActual] == '#') {
                                matriz[filaActual-1][columnaActual] = '+';
                            }
                        }
                        //abajo
                        if (filaActual + 1 <= 10) {
                            if (matriz[filaActual+1][columnaActual] == '#') {
                                matriz[filaActual+1][columnaActual] = '+';
                            }
                        }
                        //Izquierda
                        if (columnaActual - 1 >= 0) {
                            if (matriz[filaActual][columnaActual-1] == '#') {
                                matriz[filaActual][columnaActual-1] = '+';
                            }
                        }
                        //Derecha
                        if (columnaActual + 1 <= 10) {
                            if (matriz[filaActual][columnaActual+1] == '#') {
                                matriz[filaActual][columnaActual+1] = '+';
                            }
                        }
                        //Diagonal Izquierda Arriba
                        if ((filaActual - 1 >= 0) && (columnaActual - 1 >= 0)) {
                            if (matriz[filaActual-1][columnaActual - 1] == '#') {
                                matriz[filaActual-1][columnaActual - 1] = '+';
                            }
                        }
                        //Diagonal Izquierda Abajo
                        if ((filaActual + 1 <= 10) && (columnaActual - 1 >= 0)) {
                            if (matriz[filaActual+1][columnaActual - 1] == '#') {
                                matriz[filaActual+1][columnaActual - 1] = '+';
                            }
                        }
                        //Diagonal Derecha Arriba
                        if ((filaActual - 1 >= 0) && (columnaActual + 1 <= 10)) {
                            if (matriz[filaActual-1][columnaActual + 1] == '#') {
                                matriz[filaActual-1][columnaActual + 1] = '+';
                            }
                        }
                        //Diagonal Derecha Abajo
                        if ((filaActual + 1 < 10) && (columnaActual + 1 <= 10)) {
                            if (matriz[filaActual + 1][columnaActual + 1] == '#') {
                                matriz[filaActual + 1][columnaActual + 1] = '+';
                            }
                        }
                    } else {
                        cout << "No puede saltar piezas. Turno perdido." << endl;
                    }
                }
                if (espacios == 2) {
                    columnaActual+=2;
                    if (matriz[filaActual][columnaActual] == ' ') {
                        columnaActual-=2;
                        columnaActual+=espacios;
                        matriz[filaActual][columnaActual] = '+';
                        //Arriba
                        if (filaActual - 1 >= 0) {
                            if (matriz[filaActual-1][columnaActual] == '#') {
                                matriz[filaActual-1][columnaActual] = '+';
                            }
                        }
                        //abajo
                        if (filaActual + 1 <= 10) {
                            if (matriz[filaActual+1][columnaActual] == '#') {
                                matriz[filaActual+1][columnaActual] = '+';
                            }
                        }
                        //Izquierda
                        if (columnaActual - 1 >= 0) {
                            if (matriz[filaActual][columnaActual-1] == '#') {
                                matriz[filaActual][columnaActual-1] = '+';
                            }
                        }
                        //Derecha
                        if (columnaActual + 1 <= 10) {
                            if (matriz[filaActual][columnaActual+1] == '#') {
                                matriz[filaActual][columnaActual+1] = '+';
                            }
                        }
                        //Diagonal Izquierda Arriba
                        if ((filaActual - 1 >= 0) && (columnaActual - 1 >= 0)) {
                            if (matriz[filaActual-1][columnaActual - 1] == '#') {
                                matriz[filaActual-1][columnaActual - 1] = '+';
                            }
                        }
                        //Diagonal Izquierda Abajo
                        if ((filaActual + 1 <= 10) && (columnaActual - 1 >= 0)) {
                            if (matriz[filaActual+1][columnaActual - 1] == '#') {
                                matriz[filaActual+1][columnaActual - 1] = '+';
                            }
                        }
                        //Diagonal Derecha Arriba
                        if ((filaActual - 1 >= 0) && (columnaActual + 1 <= 10)) {
                            if (matriz[filaActual-1][columnaActual + 1] == '#') {
                                matriz[filaActual-1][columnaActual + 1] = '+';
                            }
                        }
                        //Diagonal Derecha Abajo
                        if ((filaActual + 1 < 10) && (columnaActual + 1 <= 10)) {
                            if (matriz[filaActual + 1][columnaActual + 1] == '#') {
                                matriz[filaActual + 1][columnaActual + 1] = '+';
                            }
                        }
                    } else {
                        cout << "No puede saltar piezas. Turno perdido." << endl;
                    }
                }
            }//Fin del else
        }//Fin del if direccion 4
        if (direccion == 5) {
            if ((filaActual - espacios < 0) || (columnaActual - espacios < 0)) {
                cout << "Posicion invalida, pierde su turno." << endl;
            } else {
                if (espacios == 1) {
                    filaActual-=1;
                    columnaActual-=1;
                    if (matriz[filaActual][columnaActual] == ' ') {
                        filaActual++;
                        columnaActual++;
                        filaActual-=espacios;
                        columnaActual-=espacios;
                        matriz[filaActual][columnaActual] = '+';
                        //Arriba
                        if (filaActual - 1 >= 0) {
                            if (matriz[filaActual-1][columnaActual] == '#') {
                                matriz[filaActual-1][columnaActual] = '+';
                            }
                        }
                        //abajo
                        if (filaActual + 1 <= 10) {
                            if (matriz[filaActual+1][columnaActual] == '#') {
                                matriz[filaActual+1][columnaActual] = '+';
                            }
                        }
                        //Izquierda
                        if (columnaActual - 1 >= 0) {
                            if (matriz[filaActual][columnaActual-1] == '#') {
                                matriz[filaActual][columnaActual-1] = '+';
                            }
                        }
                        //Derecha
                        if (columnaActual + 1 <= 10) {
                            if (matriz[filaActual][columnaActual+1] == '#') {
                                matriz[filaActual][columnaActual+1] = '+';
                            }
                        }
                        //Diagonal Izquierda Arriba
                        if ((filaActual - 1 >= 0) && (columnaActual - 1 >= 0)) {
                            if (matriz[filaActual-1][columnaActual - 1] == '#') {
                                matriz[filaActual-1][columnaActual - 1] = '+';
                            }
                        }
                        //Diagonal Izquierda Abajo
                        if ((filaActual + 1 <= 10) && (columnaActual - 1 >= 0)) {
                            if (matriz[filaActual+1][columnaActual - 1] == '#') {
                                matriz[filaActual+1][columnaActual - 1] = '+';
                            }
                        }
                        //Diagonal Derecha Arriba
                        if ((filaActual - 1 >= 0) && (columnaActual + 1 <= 10)) {
                            if (matriz[filaActual-1][columnaActual + 1] == '#') {
                                matriz[filaActual-1][columnaActual + 1] = '+';
                            }
                        }
                        //Diagonal Derecha Abajo
                        if ((filaActual + 1 < 10) && (columnaActual + 1 <= 10)) {
                            if (matriz[filaActual + 1][columnaActual + 1] == '#') {
                                matriz[filaActual + 1][columnaActual + 1] = '+';
                            }
                        }
                    } else {
                        cout << "No puede saltar piezas. Turno perdido." << endl;
                    }
                }
                if (espacios == 2) {
                    filaActual-=2;
                    columnaActual-=2;
                    if (matriz[filaActual][columnaActual] == ' ') {
                        filaActual+=2;
                        columnaActual+=2;
                        filaActual-=espacios;
                        columnaActual-=espacios;
                        matriz[filaActual][columnaActual] = '+';
                        //Arriba
                        if (filaActual - 1 >= 0) {
                            if (matriz[filaActual-1][columnaActual] == '#') {
                                matriz[filaActual-1][columnaActual] = '+';
                            }
                        }
                        //abajo
                        if (filaActual + 1 <= 10) {
                            if (matriz[filaActual+1][columnaActual] == '#') {
                                matriz[filaActual+1][columnaActual] = '+';
                            }
                        }
                        //Izquierda
                        if (columnaActual - 1 >= 0) {
                            if (matriz[filaActual][columnaActual-1] == '#') {
                                matriz[filaActual][columnaActual-1] = '+';
                            }
                        }
                        //Derecha
                        if (columnaActual + 1 <= 10) {
                            if (matriz[filaActual][columnaActual+1] == '#') {
                                matriz[filaActual][columnaActual+1] = '+';
                            }
                        }
                        //Diagonal Izquierda Arriba
                        if ((filaActual - 1 >= 0) && (columnaActual - 1 >= 0)) {
                            if (matriz[filaActual-1][columnaActual - 1] == '#') {
                                matriz[filaActual-1][columnaActual - 1] = '+';
                            }
                        }
                        //Diagonal Izquierda Abajo
                        if ((filaActual + 1 <= 10) && (columnaActual - 1 >= 0)) {
                            if (matriz[filaActual+1][columnaActual - 1] == '#') {
                                matriz[filaActual+1][columnaActual - 1] = '+';
                            }
                        }
                        //Diagonal Derecha Arriba
                        if ((filaActual - 1 >= 0) && (columnaActual + 1 <= 10)) {
                            if (matriz[filaActual-1][columnaActual + 1] == '#') {
                                matriz[filaActual-1][columnaActual + 1] = '+';
                            }
                        }
                        //Diagonal Derecha Abajo
                        if ((filaActual + 1 < 10) && (columnaActual + 1 <= 10)) {
                            if (matriz[filaActual + 1][columnaActual + 1] == '#') {
                                matriz[filaActual + 1][columnaActual + 1] = '+';
                            }
                        }
                    } else {
                        cout << "No puede saltar piezas. Turno perdido." << endl;
                    }
                }
            }//Fin del else
        }//Fin del if direccion 5
        if (direccion == 6) {
            if ((filaActual + espacios > 10) || (columnaActual - espacios < 0)) {
                cout << "Posicion invalida, pierde su turno." << endl;
            } else {
                if (espacios == 1) {
                    filaActual+=1;
                    columnaActual-=1;
                    if (matriz[filaActual][columnaActual] == ' ') {
                        filaActual--;
                        columnaActual++;
                        filaActual+=espacios;
                        columnaActual-=espacios;
                        matriz[filaActual][columnaActual] = '+';
                        //Arriba
                        if (filaActual - 1 >= 0) {
                            if (matriz[filaActual-1][columnaActual] == '#') {
                                matriz[filaActual-1][columnaActual] = '+';
                            }
                        }
                        //abajo
                        if (filaActual + 1 <= 10) {
                            if (matriz[filaActual+1][columnaActual] == '#') {
                                matriz[filaActual+1][columnaActual] = '+';
                            }
                        }
                        //Izquierda
                        if (columnaActual - 1 >= 0) {
                            if (matriz[filaActual][columnaActual-1] == '#') {
                                matriz[filaActual][columnaActual-1] = '+';
                            }
                        }
                        //Derecha
                        if (columnaActual + 1 <= 10) {
                            if (matriz[filaActual][columnaActual+1] == '#') {
                                matriz[filaActual][columnaActual+1] = '+';
                            }
                        }
                        //Diagonal Izquierda Arriba
                        if ((filaActual - 1 >= 0) && (columnaActual - 1 >= 0)) {
                            if (matriz[filaActual-1][columnaActual - 1] == '#') {
                                matriz[filaActual-1][columnaActual - 1] = '+';
                            }
                        }
                        //Diagonal Izquierda Abajo
                        if ((filaActual + 1 <= 10) && (columnaActual - 1 >= 0)) {
                            if (matriz[filaActual+1][columnaActual - 1] == '#') {
                                matriz[filaActual+1][columnaActual - 1] = '+';
                            }
                        }
                        //Diagonal Derecha Arriba
                        if ((filaActual - 1 >= 0) && (columnaActual + 1 <= 10)) {
                            if (matriz[filaActual-1][columnaActual + 1] == '#') {
                                matriz[filaActual-1][columnaActual + 1] = '+';
                            }
                        }
                        //Diagonal Derecha Abajo
                        if ((filaActual + 1 < 10) && (columnaActual + 1 <= 10)) {
                            if (matriz[filaActual + 1][columnaActual + 1] == '#') {
                                matriz[filaActual + 1][columnaActual + 1] = '+';
                            }
                        }
                    } else {
                        cout << "No puede saltar piezas. Turno perdido." << endl;
                    }
                }
                if (espacios == 2) {
                    filaActual+=2;
                    columnaActual-=2;
                    if (matriz[filaActual][columnaActual] == ' ') {
                        filaActual-=2;
                        columnaActual+=2;
                        filaActual+=espacios;
                        columnaActual-=espacios;
                        matriz[filaActual][columnaActual] = '+';
                        //Arriba
                        if (filaActual - 1 >= 0) {
                            if (matriz[filaActual-1][columnaActual] == '#') {
                                matriz[filaActual-1][columnaActual] = '+';
                            }
                        }
                        //abajo
                        if (filaActual + 1 <= 10) {
                            if (matriz[filaActual+1][columnaActual] == '#') {
                                matriz[filaActual+1][columnaActual] = '+';
                            }
                        }
                        //Izquierda
                        if (columnaActual - 1 >= 0) {
                            if (matriz[filaActual][columnaActual-1] == '#') {
                                matriz[filaActual][columnaActual-1] = '+';
                            }
                        }
                        //Derecha
                        if (columnaActual + 1 <= 10) {
                            if (matriz[filaActual][columnaActual+1] == '#') {
                                matriz[filaActual][columnaActual+1] = '+';
                            }
                        }
                        //Diagonal Izquierda Arriba
                        if ((filaActual - 1 >= 0) && (columnaActual - 1 >= 0)) {
                            if (matriz[filaActual-1][columnaActual - 1] == '#') {
                                matriz[filaActual-1][columnaActual - 1] = '+';
                            }
                        }
                        //Diagonal Izquierda Abajo
                        if ((filaActual + 1 <= 10) && (columnaActual - 1 >= 0)) {
                            if (matriz[filaActual+1][columnaActual - 1] == '#') {
                                matriz[filaActual+1][columnaActual - 1] = '+';
                            }
                        }
                        //Diagonal Derecha Arriba
                        if ((filaActual - 1 >= 0) && (columnaActual + 1 <= 10)) {
                            if (matriz[filaActual-1][columnaActual + 1] == '#') {
                                matriz[filaActual-1][columnaActual + 1] = '+';
                            }
                        }
                        //Diagonal Derecha Abajo
                        if ((filaActual + 1 < 10) && (columnaActual + 1 <= 10)) {
                            if (matriz[filaActual + 1][columnaActual + 1] == '#') {
                                matriz[filaActual + 1][columnaActual + 1] = '+';
                            }
                        }
                    } else {
                        cout << "No puede saltar piezas. Turno perdido." << endl;
                    }
                }
            }//Fin del else
        }//Fin del if direccion 6
        if (direccion == 7) {
            if ((filaActual - espacios < 0) || (columnaActual + espacios > 10)) {
                cout << "Posicion invalida, pierde su turno." << endl;
            } else {
                if (espacios == 1) {
                    filaActual-=1;
                    columnaActual+=1;
                    if (matriz[filaActual][columnaActual] == ' ') {
                        filaActual++;
                        columnaActual--;
                        filaActual-=espacios;
                        columnaActual+=espacios;
                        matriz[filaActual][columnaActual] = '+';
                        //Arriba
                        if (filaActual - 1 >= 0) {
                            if (matriz[filaActual-1][columnaActual] == '#') {
                                matriz[filaActual-1][columnaActual] = '+';
                            }
                        }
                        //abajo
                        if (filaActual + 1 <= 10) {
                            if (matriz[filaActual+1][columnaActual] == '#') {
                                matriz[filaActual+1][columnaActual] = '+';
                            }
                        }
                        //Izquierda
                        if (columnaActual - 1 >= 0) {
                            if (matriz[filaActual][columnaActual-1] == '#') {
                                matriz[filaActual][columnaActual-1] = '+';
                            }
                        }
                        //Derecha
                        if (columnaActual + 1 <= 10) {
                            if (matriz[filaActual][columnaActual+1] == '#') {
                                matriz[filaActual][columnaActual+1] = '+';
                            }
                        }
                        //Diagonal Izquierda Arriba
                        if ((filaActual - 1 >= 0) && (columnaActual - 1 >= 0)) {
                            if (matriz[filaActual-1][columnaActual - 1] == '#') {
                                matriz[filaActual-1][columnaActual - 1] = '+';
                            }
                        }
                        //Diagonal Izquierda Abajo
                        if ((filaActual + 1 <= 10) && (columnaActual - 1 >= 0)) {
                            if (matriz[filaActual+1][columnaActual - 1] == '#') {
                                matriz[filaActual+1][columnaActual - 1] = '+';
                            }
                        }
                        //Diagonal Derecha Arriba
                        if ((filaActual - 1 >= 0) && (columnaActual + 1 <= 10)) {
                            if (matriz[filaActual-1][columnaActual + 1] == '#') {
                                matriz[filaActual-1][columnaActual + 1] = '+';
                            }
                        }
                        //Diagonal Derecha Abajo
                        if ((filaActual + 1 < 10) && (columnaActual + 1 <= 10)) {
                            if (matriz[filaActual + 1][columnaActual + 1] == '#') {
                                matriz[filaActual + 1][columnaActual + 1] = '+';
                            }
                        }
                    } else {
                        cout << "No puede saltar piezas. Turno perdido." << endl;
                    }
                }
                if (espacios == 2) {
                    filaActual-=2;
                    columnaActual+=2;
                    if (matriz[filaActual][columnaActual] == ' ') {
                        filaActual+=2;
                        columnaActual-=2;
                        filaActual-=espacios;
                        columnaActual+=espacios;
                        matriz[filaActual][columnaActual] = '+';
                        //Arriba
                        if (filaActual - 1 >= 0) {
                            if (matriz[filaActual-1][columnaActual] == '#') {
                                matriz[filaActual-1][columnaActual] = '+';
                            }
                        }
                        //abajo
                        if (filaActual + 1 <= 10) {
                            if (matriz[filaActual+1][columnaActual] == '#') {
                                matriz[filaActual+1][columnaActual] = '+';
                            }
                        }
                        //Izquierda
                        if (columnaActual - 1 >= 0) {
                            if (matriz[filaActual][columnaActual-1] == '#') {
                                matriz[filaActual][columnaActual-1] = '+';
                            }
                        }
                        //Derecha
                        if (columnaActual + 1 <= 10) {
                            if (matriz[filaActual][columnaActual+1] == '#') {
                                matriz[filaActual][columnaActual+1] = '+';
                            }
                        }
                        //Diagonal Izquierda Arriba
                        if ((filaActual - 1 >= 0) && (columnaActual - 1 >= 0)) {
                            if (matriz[filaActual-1][columnaActual - 1] == '#') {
                                matriz[filaActual-1][columnaActual - 1] = '+';
                            }
                        }
                        //Diagonal Izquierda Abajo
                        if ((filaActual + 1 <= 10) && (columnaActual - 1 >= 0)) {
                            if (matriz[filaActual+1][columnaActual - 1] == '#') {
                                matriz[filaActual+1][columnaActual - 1] = '+';
                            }
                        }
                        //Diagonal Derecha Arriba
                        if ((filaActual - 1 >= 0) && (columnaActual + 1 <= 10)) {
                            if (matriz[filaActual-1][columnaActual + 1] == '#') {
                                matriz[filaActual-1][columnaActual + 1] = '+';
                            }
                        }
                        //Diagonal Derecha Abajo
                        if ((filaActual + 1 < 10) && (columnaActual + 1 <= 10)) {
                            if (matriz[filaActual + 1][columnaActual + 1] == '#') {
                                matriz[filaActual + 1][columnaActual + 1] = '+';
                            }
                        }
                    } else {
                        cout << "No puede saltar piezas. Turno perdido." << endl;
                    }
                }
            }//Fin del else
        }//Fin del if direccion 7
        if (direccion == 8) {
            if ((filaActual + espacios > 10) || (columnaActual + espacios > 10)) {
                cout << "Posicion invalida, pierde su turno." << endl;
            } else {
                if (espacios == 1) {
                    filaActual+=1;
                    columnaActual+=1;
                    if (matriz[filaActual][columnaActual] == ' ') {
                        filaActual--;
                        columnaActual--;
                        filaActual+=1;
                        columnaActual+=1;
                        matriz[filaActual][columnaActual] = '+';
                        //Arriba
                        if (filaActual - 1 >= 0) {
                            if (matriz[filaActual-1][columnaActual] == '#') {
                                matriz[filaActual-1][columnaActual] = '+';
                            }
                        }
                        //abajo
                        if (filaActual + 1 <= 10) {
                            if (matriz[filaActual+1][columnaActual] == '#') {
                                matriz[filaActual+1][columnaActual] = '+';
                            }
                        }
                        //Izquierda
                        if (columnaActual - 1 >= 0) {
                            if (matriz[filaActual][columnaActual-1] == '#') {
                                matriz[filaActual][columnaActual-1] = '+';
                            }
                        }
                        //Derecha
                        if (columnaActual + 1 <= 10) {
                            if (matriz[filaActual][columnaActual+1] == '#') {
                                matriz[filaActual][columnaActual+1] = '+';
                            }
                        }
                        //Diagonal Izquierda Arriba
                        if ((filaActual - 1 >= 0) && (columnaActual - 1 >= 0)) {
                            if (matriz[filaActual-1][columnaActual - 1] == '#') {
                                matriz[filaActual-1][columnaActual - 1] = '+';
                            }
                        }
                        //Diagonal Izquierda Abajo
                        if ((filaActual + 1 <= 10) && (columnaActual - 1 >= 0)) {
                            if (matriz[filaActual+1][columnaActual - 1] == '#') {
                                matriz[filaActual+1][columnaActual - 1] = '+';
                            }
                        }
                        //Diagonal Derecha Arriba
                        if ((filaActual - 1 >= 0) && (columnaActual + 1 <= 10)) {
                            if (matriz[filaActual-1][columnaActual + 1] == '#') {
                                matriz[filaActual-1][columnaActual + 1] = '+';
                            }
                        }
                        //Diagonal Derecha Abajo
                        if ((filaActual + 1 < 10) && (columnaActual + 1 <= 10)) {
                            if (matriz[filaActual + 1][columnaActual + 1] == '#') {
                                matriz[filaActual + 1][columnaActual + 1] = '+';
                            }
                        }
                    } else {
                        cout << "No puede saltar piezas. Turno perdido." << endl;
                    }
                }
                if (espacios == 2) {
                    filaActual+=2;
                    columnaActual+=2;
                    if (matriz[filaActual][columnaActual] == ' ') {
                        filaActual-=2;
                        columnaActual-=2;
                        filaActual+=espacios;
                        columnaActual+=espacios;
                        matriz[filaActual][columnaActual] = '+';
                        //Arriba
                        if (filaActual - 1 >= 0) {
                            if (matriz[filaActual-1][columnaActual] == '#') {
                                matriz[filaActual-1][columnaActual] = '+';
                            }
                        }
                        //abajo
                        if (filaActual + 1 <= 10) {
                            if (matriz[filaActual+1][columnaActual] == '#') {
                                matriz[filaActual+1][columnaActual] = '+';
                            }
                        }
                        //Izquierda
                        if (columnaActual - 1 >= 0) {
                            if (matriz[filaActual][columnaActual-1] == '#') {
                                matriz[filaActual][columnaActual-1] = '+';
                            }
                        }
                        //Derecha
                        if (columnaActual + 1 <= 10) {
                            if (matriz[filaActual][columnaActual+1] == '#') {
                                matriz[filaActual][columnaActual+1] = '+';
                            }
                        }
                        //Diagonal Izquierda Arriba
                        if ((filaActual - 1 >= 0) && (columnaActual - 1 >= 0)) {
                            if (matriz[filaActual-1][columnaActual - 1] == '#') {
                                matriz[filaActual-1][columnaActual - 1] = '+';
                            }
                        }
                        //Diagonal Izquierda Abajo
                        if ((filaActual + 1 <= 10) && (columnaActual - 1 >= 0)) {
                            if (matriz[filaActual+1][columnaActual - 1] == '#') {
                                matriz[filaActual+1][columnaActual - 1] = '+';
                            }
                        }
                        //Diagonal Derecha Arriba
                        if ((filaActual - 1 >= 0) && (columnaActual + 1 <= 10)) {
                            if (matriz[filaActual-1][columnaActual + 1] == '#') {
                                matriz[filaActual-1][columnaActual + 1] = '+';
                            }
                        }
                        //Diagonal Derecha Abajo
                        if ((filaActual + 1 < 10) && (columnaActual + 1 <= 10)) {
                            if (matriz[filaActual + 1][columnaActual + 1] == '#') {
                                matriz[filaActual + 1][columnaActual + 1] = '+';
                            }
                        }
                    } else {
                        cout << "No puede saltar piezas. Turno perdido." << endl;
                    }
                }
            }//Fin del else
        }//Fin del if direccion 8
    }
    if (jugador == 2) {
        cout << "Cuantos espacios se quiere mover (1 o 2):";
        cin >> espacios;
        if (espacios <= 0 || espacios > 2) {
            do {
                cout << "Valor invalido." << endl;
                cout << "Cuantos espacios se quiere mover (1 o 2):";
                cin >> espacios;
            } while (espacios <= 0 || espacios > 2);
        }//Fin del verificador
        cout << "Arriba: 1" << endl;
        cout << "Abajo: 2" << endl;
        cout << "Izquierda: 3" << endl;
        cout << "Derecha: 4" << endl;
        cout << "Diagonal Izquierda Arriba: 5" << endl;
        cout << "Diagonal Izquierda Abajo: 6" << endl;
        cout << "Diagonal Derecha Arriba: 7" << endl;
        cout << "Diagonal Derecha Abajo: 8" << endl;
        cout << "Ingrese su direccion: ";
        cin >> direccion;
        cout << endl;
        if (direccion == 1) {
            if (filaActual - espacios < 0) {
                cout << "Posicion invalida, pierde su turno." << endl;
            } else {
                if (espacios == 1) {
                    filaActual-=1;
                    if (matriz[filaActual][columnaActual] == ' ') {
                        filaActual++;
                        filaActual-=espacios;
                        matriz[filaActual][columnaActual] = '#';
                        //Arriba
                        if (filaActual - 1 >= 0) {
                            if (matriz[filaActual-1][columnaActual] == '+') {
                                matriz[filaActual-1][columnaActual] = '#';
                            }
                        }
                        //abajo
                        if (filaActual + 1 <= 10) {
                            if (matriz[filaActual+1][columnaActual] == '+') {
                                matriz[filaActual+1][columnaActual] = '#';
                            }
                        }
                        //Izquierda
                        if (columnaActual - 1 >= 0) {
                            if (matriz[filaActual][columnaActual-1] == '+') {
                                matriz[filaActual][columnaActual-1] = '#';
                            }
                        }
                        //Derecha
                        if (columnaActual + 1 <= 10) {
                            if (matriz[filaActual][columnaActual+1] == '+') {
                                matriz[filaActual][columnaActual+1] = '#';
                            }
                        }
                        //Diagonal Izquierda Arriba
                        if ((filaActual - 1 >= 0) && (columnaActual - 1 >= 0)) {
                            if (matriz[filaActual-1][columnaActual - 1] == '+') {
                                matriz[filaActual-1][columnaActual - 1] = '#';
                            }
                        }
                        //Diagonal Izquierda Abajo
                        if ((filaActual + 1 <= 10) && (columnaActual - 1 >= 0)) {
                            if (matriz[filaActual+1][columnaActual - 1] == '+') {
                                matriz[filaActual+1][columnaActual - 1] = '#';
                            }
                        }
                        //Diagonal Derecha Arriba
                        if ((filaActual - 1 >= 0) && (columnaActual + 1 <= 10)) {
                            if (matriz[filaActual-1][columnaActual + 1] == '+') {
                                matriz[filaActual-1][columnaActual + 1] = '#';
                            }
                        }
                        //Diagonal Derecha Abajo
                        if ((filaActual + 1 < 10) && (columnaActual + 1 <= 10)) {
                            if (matriz[filaActual + 1][columnaActual + 1] == '+') {
                                matriz[filaActual + 1][columnaActual + 1] = '#';
                            }
                        }
                    } else {
                        cout << "No puede saltar piezas. Turno perdido." << endl;
                    }
                }
                if (espacios == 2) {
                    filaActual-=2;
                    if (matriz[filaActual][columnaActual] == ' ') {
                        filaActual+=2;
                        filaActual-=espacios;
                        matriz[filaActual][columnaActual] = '#';
                        //Arriba
                        if (filaActual - 1 >= 0) {
                            if (matriz[filaActual-1][columnaActual] == '+') {
                                matriz[filaActual-1][columnaActual] = '#';
                            }
                        }
                        //abajo
                        if (filaActual + 1 <= 10) {
                            if (matriz[filaActual+1][columnaActual] == '+') {
                                matriz[filaActual+1][columnaActual] = '#';
                            }
                        }
                        //Izquierda
                        if (columnaActual - 1 >= 0) {
                            if (matriz[filaActual][columnaActual-1] == '+') {
                                matriz[filaActual][columnaActual-1] = '#';
                            }
                        }
                        //Derecha
                        if (columnaActual + 1 <= 10) {
                            if (matriz[filaActual][columnaActual+1] == '+') {
                                matriz[filaActual][columnaActual+1] = '#';
                            }
                        }
                        //Diagonal Izquierda Arriba
                        if ((filaActual - 1 >= 0) && (columnaActual - 1 >= 0)) {
                            if (matriz[filaActual-1][columnaActual - 1] == '+') {
                                matriz[filaActual-1][columnaActual - 1] = '#';
                            }
                        }
                        //Diagonal Izquierda Abajo
                        if ((filaActual + 1 <= 10) && (columnaActual - 1 >= 0)) {
                            if (matriz[filaActual+1][columnaActual - 1] == '+') {
                                matriz[filaActual+1][columnaActual - 1] = '#';
                            }
                        }
                        //Diagonal Derecha Arriba
                        if ((filaActual - 1 >= 0) && (columnaActual + 1 <= 10)) {
                            if (matriz[filaActual-1][columnaActual + 1] == '+') {
                                matriz[filaActual-1][columnaActual + 1] = '#';
                            }
                        }
                        //Diagonal Derecha Abajo
                        if ((filaActual + 1 < 10) && (columnaActual + 1 <= 10)) {
                            if (matriz[filaActual + 1][columnaActual + 1] == '+') {
                                matriz[filaActual + 1][columnaActual + 1] = '#';
                            }
                        }
                    } else {
                        cout << "No puede saltar piezas. Turno perdido." << endl;
                    }
                }
            }//Fin del else
        }//FIn del if direccion
        if (direccion == 2) {
            if (filaActual + espacios > 10) {
                cout << "Posicion invalida, pierde su turno." << endl;
            } else {
                if (espacios == 1) {
                    filaActual+=1;
                    if (matriz[filaActual][columnaActual] == ' ') {
                        filaActual--;
                        filaActual+=espacios;
                        matriz[filaActual][columnaActual] = '#';
                        //Arriba
                        if (filaActual - 1 >= 0) {
                            if (matriz[filaActual-1][columnaActual] == '+') {
                                matriz[filaActual-1][columnaActual] = '#';
                            }
                        }
                        //abajo
                        if (filaActual + 1 <= 10) {
                            if (matriz[filaActual+1][columnaActual] == '+') {
                                matriz[filaActual+1][columnaActual] = '#';
                            }
                        }
                        //Izquierda
                        if (columnaActual - 1 >= 0) {
                            if (matriz[filaActual][columnaActual-1] == '+') {
                                matriz[filaActual][columnaActual-1] = '#';
                            }
                        }
                        //Derecha
                        if (columnaActual + 1 <= 10) {
                            if (matriz[filaActual][columnaActual+1] == '+') {
                                matriz[filaActual][columnaActual+1] = '#';
                            }
                        }
                        //Diagonal Izquierda Arriba
                        if ((filaActual - 1 >= 0) && (columnaActual - 1 >= 0)) {
                            if (matriz[filaActual-1][columnaActual - 1] == '+') {
                                matriz[filaActual-1][columnaActual - 1] = '#';
                            }
                        }
                        //Diagonal Izquierda Abajo
                        if ((filaActual + 1 <= 10) && (columnaActual - 1 >= 0)) {
                            if (matriz[filaActual+1][columnaActual - 1] == '+') {
                                matriz[filaActual+1][columnaActual - 1] = '#';
                            }
                        }
                        //Diagonal Derecha Arriba
                        if ((filaActual - 1 >= 0) && (columnaActual + 1 <= 10)) {
                            if (matriz[filaActual-1][columnaActual + 1] == '+') {
                                matriz[filaActual-1][columnaActual + 1] = '#';
                            }
                        }
                        //Diagonal Derecha Abajo
                        if ((filaActual + 1 < 10) && (columnaActual + 1 <= 10)) {
                            if (matriz[filaActual + 1][columnaActual + 1] == '+') {
                                matriz[filaActual + 1][columnaActual + 1] = '#';
                            }
                        }
                    } else {
                        cout << "No puede saltar piezas. Turno perdido." << endl;
                    }
                }
                if (espacios == 2) {
                    filaActual+=2;
                    if (matriz[filaActual][columnaActual] == ' ') {
                        filaActual-=2;
                        filaActual+=espacios;
                        matriz[filaActual][columnaActual] = '#';
                        //Arriba
                        if (filaActual - 1 >= 0) {
                            if (matriz[filaActual-1][columnaActual] == '+') {
                                matriz[filaActual-1][columnaActual] = '#';
                            }
                        }
                        //abajo
                        if (filaActual + 1 <= 10) {
                            if (matriz[filaActual+1][columnaActual] == '+') {
                                matriz[filaActual+1][columnaActual] = '#';
                            }
                        }
                        //Izquierda
                        if (columnaActual - 1 >= 0) {
                            if (matriz[filaActual][columnaActual-1] == '+') {
                                matriz[filaActual][columnaActual-1] = '#';
                            }
                        }
                        //Derecha
                        if (columnaActual + 1 <= 10) {
                            if (matriz[filaActual][columnaActual+1] == '+') {
                                matriz[filaActual][columnaActual+1] = '#';
                            }
                        }
                        //Diagonal Izquierda Arriba
                        if ((filaActual - 1 >= 0) && (columnaActual - 1 >= 0)) {
                            if (matriz[filaActual-1][columnaActual - 1] == '+') {
                                matriz[filaActual-1][columnaActual - 1] = '#';
                            }
                        }
                        //Diagonal Izquierda Abajo
                        if ((filaActual + 1 <= 10) && (columnaActual - 1 >= 0)) {
                            if (matriz[filaActual+1][columnaActual - 1] == '+') {
                                matriz[filaActual+1][columnaActual - 1] = '#';
                            }
                        }
                        //Diagonal Derecha Arriba
                        if ((filaActual - 1 >= 0) && (columnaActual + 1 <= 10)) {
                            if (matriz[filaActual-1][columnaActual + 1] == '+') {
                                matriz[filaActual-1][columnaActual + 1] = '#';
                            }
                        }
                        //Diagonal Derecha Abajo
                        if ((filaActual + 1 < 10) && (columnaActual + 1 <= 10)) {
                            if (matriz[filaActual + 1][columnaActual + 1] == '+') {
                                matriz[filaActual + 1][columnaActual + 1] = '#';
                            }
                        }
                    } else {
                        cout << "No puede saltar piezas. Turno perdido." << endl;
                    }
                }
            }//Fin del else
        }//Fin de la direccion 2
        if (direccion == 3) {
            if (columnaActual - espacios < 0) {
                cout << "Posicion invalida, pierde su turno." << endl;
            } else {
                if (espacios == 1) {
                    columnaActual-=1;
                    if (matriz[filaActual][columnaActual] == ' ') {
                        columnaActual++;
                        columnaActual-=espacios;
                        matriz[filaActual][columnaActual] = '#';
                        //Arriba
                        if (filaActual - 1 >= 0) {
                            if (matriz[filaActual-1][columnaActual] == '+') {
                                matriz[filaActual-1][columnaActual] = '#';
                            }
                        }
                        //abajo
                        if (filaActual + 1 <= 10) {
                            if (matriz[filaActual+1][columnaActual] == '+') {
                                matriz[filaActual+1][columnaActual] = '#';
                            }
                        }
                        //Izquierda
                        if (columnaActual - 1 >= 0) {
                            if (matriz[filaActual][columnaActual-1] == '+') {
                                matriz[filaActual][columnaActual-1] = '#';
                            }
                        }
                        //Derecha
                        if (columnaActual + 1 <= 10) {
                            if (matriz[filaActual][columnaActual+1] == '+') {
                                matriz[filaActual][columnaActual+1] = '#';
                            }
                        }
                        //Diagonal Izquierda Arriba
                        if ((filaActual - 1 >= 0) && (columnaActual - 1 >= 0)) {
                            if (matriz[filaActual-1][columnaActual - 1] == '+') {
                                matriz[filaActual-1][columnaActual - 1] = '#';
                            }
                        }
                        //Diagonal Izquierda Abajo
                        if ((filaActual + 1 <= 10) && (columnaActual - 1 >= 0)) {
                            if (matriz[filaActual+1][columnaActual - 1] == '+') {
                                matriz[filaActual+1][columnaActual - 1] = '#';
                            }
                        }
                        //Diagonal Derecha Arriba
                        if ((filaActual - 1 >= 0) && (columnaActual + 1 <= 10)) {
                            if (matriz[filaActual-1][columnaActual + 1] == '+') {
                                matriz[filaActual-1][columnaActual + 1] = '#';
                            }
                        }
                        //Diagonal Derecha Abajo
                        if ((filaActual + 1 < 10) && (columnaActual + 1 <= 10)) {
                            if (matriz[filaActual + 1][columnaActual + 1] == '+') {
                                matriz[filaActual + 1][columnaActual + 1] = '#';
                            }
                        }
                    } else {
                        cout << "No puede saltar piezas. Turno perdido." << endl;
                    }
                }
                if (espacios == 2) {
                    columnaActual-=2;
                    if (matriz[filaActual][columnaActual] == ' ') {
                        columnaActual+=2;
                        columnaActual-=espacios;
                        matriz[filaActual][columnaActual] = '#';
                        //Arriba
                        if (filaActual - 1 >= 0) {
                            if (matriz[filaActual-1][columnaActual] == '+') {
                                matriz[filaActual-1][columnaActual] = '#';
                            }
                        }
                        //abajo
                        if (filaActual + 1 <= 10) {
                            if (matriz[filaActual+1][columnaActual] == '+') {
                                matriz[filaActual+1][columnaActual] = '#';
                            }
                        }
                        //Izquierda
                        if (columnaActual - 1 >= 0) {
                            if (matriz[filaActual][columnaActual-1] == '+') {
                                matriz[filaActual][columnaActual-1] = '#';
                            }
                        }
                        //Derecha
                        if (columnaActual + 1 <= 10) {
                            if (matriz[filaActual][columnaActual+1] == '+') {
                                matriz[filaActual][columnaActual+1] = '#';
                            }
                        }
                        //Diagonal Izquierda Arriba
                        if ((filaActual - 1 >= 0) && (columnaActual - 1 >= 0)) {
                            if (matriz[filaActual-1][columnaActual - 1] == '+') {
                                matriz[filaActual-1][columnaActual - 1] = '#';
                            }
                        }
                        //Diagonal Izquierda Abajo
                        if ((filaActual + 1 <= 10) && (columnaActual - 1 >= 0)) {
                            if (matriz[filaActual+1][columnaActual - 1] == '+') {
                                matriz[filaActual+1][columnaActual - 1] = '#';
                            }
                        }
                        //Diagonal Derecha Arriba
                        if ((filaActual - 1 >= 0) && (columnaActual + 1 <= 10)) {
                            if (matriz[filaActual-1][columnaActual + 1] == '+') {
                                matriz[filaActual-1][columnaActual + 1] = '#';
                            }
                        }
                        //Diagonal Derecha Abajo
                        if ((filaActual + 1 < 10) && (columnaActual + 1 <= 10)) {
                            if (matriz[filaActual + 1][columnaActual + 1] == '+') {
                                matriz[filaActual + 1][columnaActual + 1] = '#';
                            }
                        }
                    } else {
                        cout << "No puede saltar piezas. Turno perdido." << endl;
                    }
                }
            }//Fin del else
        }//Fin del if direccion 3
        if (direccion == 4) {
            if (columnaActual + espacios > 10) {
                cout << "Posicion invalida, pierde su turno." << endl;
            } else {
                if (espacios == 1) {
                    columnaActual+=1;
                    if (matriz[filaActual][columnaActual] == ' ') {
                        columnaActual--;
                        columnaActual+=espacios;
                        matriz[filaActual][columnaActual] = '#';
                        //Arriba
                        if (filaActual - 1 >= 0) {
                            if (matriz[filaActual-1][columnaActual] == '+') {
                                matriz[filaActual-1][columnaActual] = '#';
                            }
                        }
                        //abajo
                        if (filaActual + 1 <= 10) {
                            if (matriz[filaActual+1][columnaActual] == '+') {
                                matriz[filaActual+1][columnaActual] = '#';
                            }
                        }
                        //Izquierda
                        if (columnaActual - 1 >= 0) {
                            if (matriz[filaActual][columnaActual-1] == '+') {
                                matriz[filaActual][columnaActual-1] = '#';
                            }
                        }
                        //Derecha
                        if (columnaActual + 1 <= 10) {
                            if (matriz[filaActual][columnaActual+1] == '+') {
                                matriz[filaActual][columnaActual+1] = '#';
                            }
                        }
                        //Diagonal Izquierda Arriba
                        if ((filaActual - 1 >= 0) && (columnaActual - 1 >= 0)) {
                            if (matriz[filaActual-1][columnaActual - 1] == '+') {
                                matriz[filaActual-1][columnaActual - 1] = '#';
                            }
                        }
                        //Diagonal Izquierda Abajo
                        if ((filaActual + 1 <= 10) && (columnaActual - 1 >= 0)) {
                            if (matriz[filaActual+1][columnaActual - 1] == '+') {
                                matriz[filaActual+1][columnaActual - 1] = '#';
                            }
                        }
                        //Diagonal Derecha Arriba
                        if ((filaActual - 1 >= 0) && (columnaActual + 1 <= 10)) {
                            if (matriz[filaActual-1][columnaActual + 1] == '+') {
                                matriz[filaActual-1][columnaActual + 1] = '#';
                            }
                        }
                        //Diagonal Derecha Abajo
                        if ((filaActual + 1 < 10) && (columnaActual + 1 <= 10)) {
                            if (matriz[filaActual + 1][columnaActual + 1] == '+') {
                                matriz[filaActual + 1][columnaActual + 1] = '#';
                            }
                        }
                    } else {
                        cout << "No puede saltar piezas. Turno perdido." << endl;
                    }
                }
                if (espacios == 2) {
                    columnaActual+=2;
                    if (matriz[filaActual][columnaActual] == ' ') {
                        columnaActual-=2;
                        columnaActual+=espacios;
                        matriz[filaActual][columnaActual] = '#';
                        //Arriba
                        if (filaActual - 1 >= 0) {
                            if (matriz[filaActual-1][columnaActual] == '+') {
                                matriz[filaActual-1][columnaActual] = '#';
                            }
                        }
                        //abajo
                        if (filaActual + 1 <= 10) {
                            if (matriz[filaActual+1][columnaActual] == '+') {
                                matriz[filaActual+1][columnaActual] = '#';
                            }
                        }
                        //Izquierda
                        if (columnaActual - 1 >= 0) {
                            if (matriz[filaActual][columnaActual-1] == '+') {
                                matriz[filaActual][columnaActual-1] = '#';
                            }
                        }
                        //Derecha
                        if (columnaActual + 1 <= 10) {
                            if (matriz[filaActual][columnaActual+1] == '+') {
                                matriz[filaActual][columnaActual+1] = '#';
                            }
                        }
                        //Diagonal Izquierda Arriba
                        if ((filaActual - 1 >= 0) && (columnaActual - 1 >= 0)) {
                            if (matriz[filaActual-1][columnaActual - 1] == '+') {
                                matriz[filaActual-1][columnaActual - 1] = '#';
                            }
                        }
                        //Diagonal Izquierda Abajo
                        if ((filaActual + 1 <= 10) && (columnaActual - 1 >= 0)) {
                            if (matriz[filaActual+1][columnaActual - 1] == '+') {
                                matriz[filaActual+1][columnaActual - 1] = '#';
                            }
                        }
                        //Diagonal Derecha Arriba
                        if ((filaActual - 1 >= 0) && (columnaActual + 1 <= 10)) {
                            if (matriz[filaActual-1][columnaActual + 1] == '+') {
                                matriz[filaActual-1][columnaActual + 1] = '#';
                            }
                        }
                        //Diagonal Derecha Abajo
                        if ((filaActual + 1 < 10) && (columnaActual + 1 <= 10)) {
                            if (matriz[filaActual + 1][columnaActual + 1] == '+') {
                                matriz[filaActual + 1][columnaActual + 1] = '#';
                            }
                        }
                    } else {
                        cout << "No puede saltar piezas. Turno perdido." << endl;
                    }
                }
            }//Fin del else
        }//Fin del if direccion 4
        if (direccion == 5) {
            if ((filaActual - espacios < 0) || (columnaActual - espacios < 0)) {
                cout << "Posicion invalida, pierde su turno." << endl;
            } else {
                if (espacios == 1) {
                    filaActual-=1;
                    columnaActual-=1;
                    if (matriz[filaActual][columnaActual] == ' ') {
                        filaActual++;
                        columnaActual++;
                        filaActual-=espacios;
                        columnaActual-=espacios;
                        matriz[filaActual][columnaActual] = '#';
                        //Arriba
                        if (filaActual - 1 >= 0) {
                            if (matriz[filaActual-1][columnaActual] == '+') {
                                matriz[filaActual-1][columnaActual] = '#';
                            }
                        }
                        //abajo
                        if (filaActual + 1 <= 10) {
                            if (matriz[filaActual+1][columnaActual] == '+') {
                                matriz[filaActual+1][columnaActual] = '#';
                            }
                        }
                        //Izquierda
                        if (columnaActual - 1 >= 0) {
                            if (matriz[filaActual][columnaActual-1] == '+') {
                                matriz[filaActual][columnaActual-1] = '#';
                            }
                        }
                        //Derecha
                        if (columnaActual + 1 <= 10) {
                            if (matriz[filaActual][columnaActual+1] == '+') {
                                matriz[filaActual][columnaActual+1] = '#';
                            }
                        }
                        //Diagonal Izquierda Arriba
                        if ((filaActual - 1 >= 0) && (columnaActual - 1 >= 0)) {
                            if (matriz[filaActual-1][columnaActual - 1] == '+') {
                                matriz[filaActual-1][columnaActual - 1] = '#';
                            }
                        }
                        //Diagonal Izquierda Abajo
                        if ((filaActual + 1 <= 10) && (columnaActual - 1 >= 0)) {
                            if (matriz[filaActual+1][columnaActual - 1] == '+') {
                                matriz[filaActual+1][columnaActual - 1] = '#';
                            }
                        }
                        //Diagonal Derecha Arriba
                        if ((filaActual - 1 >= 0) && (columnaActual + 1 <= 10)) {
                            if (matriz[filaActual-1][columnaActual + 1] == '+') {
                                matriz[filaActual-1][columnaActual + 1] = '#';
                            }
                        }
                        //Diagonal Derecha Abajo
                        if ((filaActual + 1 < 10) && (columnaActual + 1 <= 10)) {
                            if (matriz[filaActual + 1][columnaActual + 1] == '+') {
                                matriz[filaActual + 1][columnaActual + 1] = '#';
                            }
                        }
                    } else {
                        cout << "No puede saltar piezas. Turno perdido." << endl;
                    }
                }
                if (espacios == 2) {
                    filaActual-=2;
                    columnaActual-=2;
                    if (matriz[filaActual][columnaActual] == ' ') {
                        filaActual+=2;
                        columnaActual+=2;
                        filaActual-=espacios;
                        columnaActual-=espacios;
                        matriz[filaActual][columnaActual] = '#';
                        //Arriba
                        if (filaActual - 1 >= 0) {
                            if (matriz[filaActual-1][columnaActual] == '+') {
                                matriz[filaActual-1][columnaActual] = '#';
                            }
                        }
                        //abajo
                        if (filaActual + 1 <= 10) {
                            if (matriz[filaActual+1][columnaActual] == '+') {
                                matriz[filaActual+1][columnaActual] = '#';
                            }
                        }
                        //Izquierda
                        if (columnaActual - 1 >= 0) {
                            if (matriz[filaActual][columnaActual-1] == '+') {
                                matriz[filaActual][columnaActual-1] = '#';
                            }
                        }
                        //Derecha
                        if (columnaActual + 1 <= 10) {
                            if (matriz[filaActual][columnaActual+1] == '+') {
                                matriz[filaActual][columnaActual+1] = '#';
                            }
                        }
                        //Diagonal Izquierda Arriba
                        if ((filaActual - 1 >= 0) && (columnaActual - 1 >= 0)) {
                            if (matriz[filaActual-1][columnaActual - 1] == '+') {
                                matriz[filaActual-1][columnaActual - 1] = '#';
                            }
                        }
                        //Diagonal Izquierda Abajo
                        if ((filaActual + 1 <= 10) && (columnaActual - 1 >= 0)) {
                            if (matriz[filaActual+1][columnaActual - 1] == '+') {
                                matriz[filaActual+1][columnaActual - 1] = '#';
                            }
                        }
                        //Diagonal Derecha Arriba
                        if ((filaActual - 1 >= 0) && (columnaActual + 1 <= 10)) {
                            if (matriz[filaActual-1][columnaActual + 1] == '+') {
                                matriz[filaActual-1][columnaActual + 1] = '#';
                            }
                        }
                        //Diagonal Derecha Abajo
                        if ((filaActual + 1 < 10) && (columnaActual + 1 <= 10)) {
                            if (matriz[filaActual + 1][columnaActual + 1] == '+') {
                                matriz[filaActual + 1][columnaActual + 1] = '#';
                            }
                        }
                    } else {
                        cout << "No puede saltar piezas. Turno perdido." << endl;
                    }
                }
            }//Fin del else
        }//Fin del if direccion 5
        if (direccion == 6) {
            if ((filaActual + espacios > 10) || (columnaActual - espacios < 0)) {
                cout << "Posicion invalida, pierde su turno." << endl;
            } else {
                if (espacios == 1) {
                    filaActual+=1;
                    columnaActual-=1;
                    if (matriz[filaActual][columnaActual] == ' ') {
                        filaActual--;
                        columnaActual++;
                        filaActual+=espacios;
                        columnaActual-=espacios;
                        matriz[filaActual][columnaActual] = '#';
                        //Arriba
                        if (filaActual - 1 >= 0) {
                            if (matriz[filaActual-1][columnaActual] == '+') {
                                matriz[filaActual-1][columnaActual] = '#';
                            }
                        }
                        //abajo
                        if (filaActual + 1 <= 10) {
                            if (matriz[filaActual+1][columnaActual] == '+') {
                                matriz[filaActual+1][columnaActual] = '#';
                            }
                        }
                        //Izquierda
                        if (columnaActual - 1 >= 0) {
                            if (matriz[filaActual][columnaActual-1] == '+') {
                                matriz[filaActual][columnaActual-1] = '#';
                            }
                        }
                        //Derecha
                        if (columnaActual + 1 <= 10) {
                            if (matriz[filaActual][columnaActual+1] == '+') {
                                matriz[filaActual][columnaActual+1] = '#';
                            }
                        }
                        //Diagonal Izquierda Arriba
                        if ((filaActual - 1 >= 0) && (columnaActual - 1 >= 0)) {
                            if (matriz[filaActual-1][columnaActual - 1] == '+') {
                                matriz[filaActual-1][columnaActual - 1] = '#';
                            }
                        }
                        //Diagonal Izquierda Abajo
                        if ((filaActual + 1 <= 10) && (columnaActual - 1 >= 0)) {
                            if (matriz[filaActual+1][columnaActual - 1] == '+') {
                                matriz[filaActual+1][columnaActual - 1] = '#';
                            }
                        }
                        //Diagonal Derecha Arriba
                        if ((filaActual - 1 >= 0) && (columnaActual + 1 <= 10)) {
                            if (matriz[filaActual-1][columnaActual + 1] == '+') {
                                matriz[filaActual-1][columnaActual + 1] = '#';
                            }
                        }
                        //Diagonal Derecha Abajo
                        if ((filaActual + 1 < 10) && (columnaActual + 1 <= 10)) {
                            if (matriz[filaActual + 1][columnaActual + 1] == '+') {
                                matriz[filaActual + 1][columnaActual + 1] = '#';
                            }
                        }
                    } else {
                        cout << "No puede saltar piezas. Turno perdido." << endl;
                    }
                }
                if (espacios == 2) {
                    filaActual+=2;
                    columnaActual-=2;
                    if (matriz[filaActual][columnaActual] == ' ') {
                        filaActual-=2;
                        columnaActual+=2;
                        filaActual+=espacios;
                        columnaActual-=espacios;
                        matriz[filaActual][columnaActual] = '#';
                        //Arriba
                        if (filaActual - 1 >= 0) {
                            if (matriz[filaActual-1][columnaActual] == '+') {
                                matriz[filaActual-1][columnaActual] = '#';
                            }
                        }
                        //abajo
                        if (filaActual + 1 <= 10) {
                            if (matriz[filaActual+1][columnaActual] == '+') {
                                matriz[filaActual+1][columnaActual] = '#';
                            }
                        }
                        //Izquierda
                        if (columnaActual - 1 >= 0) {
                            if (matriz[filaActual][columnaActual-1] == '+') {
                                matriz[filaActual][columnaActual-1] = '#';
                            }
                        }
                        //Derecha
                        if (columnaActual + 1 <= 10) {
                            if (matriz[filaActual][columnaActual+1] == '+') {
                                matriz[filaActual][columnaActual+1] = '#';
                            }
                        }
                        //Diagonal Izquierda Arriba
                        if ((filaActual - 1 >= 0) && (columnaActual - 1 >= 0)) {
                            if (matriz[filaActual-1][columnaActual - 1] == '+') {
                                matriz[filaActual-1][columnaActual - 1] = '#';
                            }
                        }
                        //Diagonal Izquierda Abajo
                        if ((filaActual + 1 <= 10) && (columnaActual - 1 >= 0)) {
                            if (matriz[filaActual+1][columnaActual - 1] == '+') {
                                matriz[filaActual+1][columnaActual - 1] = '#';
                            }
                        }
                        //Diagonal Derecha Arriba
                        if ((filaActual - 1 >= 0) && (columnaActual + 1 <= 10)) {
                            if (matriz[filaActual-1][columnaActual + 1] == '+') {
                                matriz[filaActual-1][columnaActual + 1] = '#';
                            }
                        }
                        //Diagonal Derecha Abajo
                        if ((filaActual + 1 < 10) && (columnaActual + 1 <= 10)) {
                            if (matriz[filaActual + 1][columnaActual + 1] == '+') {
                                matriz[filaActual + 1][columnaActual + 1] = '#';
                            }
                        }
                    } else {
                        cout << "No puede saltar piezas. Turno perdido." << endl;
                    }
                }
            }//Fin del else
        }//Fin del if direccion 6
        if (direccion == 7) {
            if ((filaActual - espacios < 0) || (columnaActual + espacios > 10)) {
                cout << "Posicion invalida, pierde su turno." << endl;
            } else {
                if (espacios == 1) {
                    filaActual-=1;
                    columnaActual+=1;
                    if (matriz[filaActual][columnaActual] == ' ') {
                        filaActual++;
                        columnaActual--;
                        filaActual-=espacios;
                        columnaActual+=espacios;
                        matriz[filaActual][columnaActual] = '#';
                        //Arriba
                        if (filaActual - 1 >= 0) {
                            if (matriz[filaActual-1][columnaActual] == '+') {
                                matriz[filaActual-1][columnaActual] = '#';
                            }
                        }
                        //abajo
                        if (filaActual + 1 <= 10) {
                            if (matriz[filaActual+1][columnaActual] == '+') {
                                matriz[filaActual+1][columnaActual] = '#';
                            }
                        }
                        //Izquierda
                        if (columnaActual - 1 >= 0) {
                            if (matriz[filaActual][columnaActual-1] == '+') {
                                matriz[filaActual][columnaActual-1] = '#';
                            }
                        }
                        //Derecha
                        if (columnaActual + 1 <= 10) {
                            if (matriz[filaActual][columnaActual+1] == '+') {
                                matriz[filaActual][columnaActual+1] = '#';
                            }
                        }
                        //Diagonal Izquierda Arriba
                        if ((filaActual - 1 >= 0) && (columnaActual - 1 >= 0)) {
                            if (matriz[filaActual-1][columnaActual - 1] == '+') {
                                matriz[filaActual-1][columnaActual - 1] = '#';
                            }
                        }
                        //Diagonal Izquierda Abajo
                        if ((filaActual + 1 <= 10) && (columnaActual - 1 >= 0)) {
                            if (matriz[filaActual+1][columnaActual - 1] == '+') {
                                matriz[filaActual+1][columnaActual - 1] = '#';
                            }
                        }
                        //Diagonal Derecha Arriba
                        if ((filaActual - 1 >= 0) && (columnaActual + 1 <= 10)) {
                            if (matriz[filaActual-1][columnaActual + 1] == '+') {
                                matriz[filaActual-1][columnaActual + 1] = '#';
                            }
                        }
                        //Diagonal Derecha Abajo
                        if ((filaActual + 1 < 10) && (columnaActual + 1 <= 10)) {
                            if (matriz[filaActual + 1][columnaActual + 1] == '+') {
                                matriz[filaActual + 1][columnaActual + 1] = '#';
                            }
                        }
                    } else {
                        cout << "No puede saltar piezas. Turno perdido." << endl;
                    }
                }
                if (espacios == 2) {
                    filaActual-=2;
                    columnaActual+=2;
                    if (matriz[filaActual][columnaActual] == ' ') {
                        filaActual+=2;
                        columnaActual-=2;
                        filaActual-=espacios;
                        columnaActual+=espacios;
                        matriz[filaActual][columnaActual] = '#';
                        //Arriba
                        if (filaActual - 1 >= 0) {
                            if (matriz[filaActual-1][columnaActual] == '+') {
                                matriz[filaActual-1][columnaActual] = '#';
                            }
                        }
                        //abajo
                        if (filaActual + 1 <= 10) {
                            if (matriz[filaActual+1][columnaActual] == '+') {
                                matriz[filaActual+1][columnaActual] = '#';
                            }
                        }
                        //Izquierda
                        if (columnaActual - 1 >= 0) {
                            if (matriz[filaActual][columnaActual-1] == '+') {
                                matriz[filaActual][columnaActual-1] = '#';
                            }
                        }
                        //Derecha
                        if (columnaActual + 1 <= 10) {
                            if (matriz[filaActual][columnaActual+1] == '+') {
                                matriz[filaActual][columnaActual+1] = '#';
                            }
                        }
                        //Diagonal Izquierda Arriba
                        if ((filaActual - 1 >= 0) && (columnaActual - 1 >= 0)) {
                            if (matriz[filaActual-1][columnaActual - 1] == '+') {
                                matriz[filaActual-1][columnaActual - 1] = '#';
                            }
                        }
                        //Diagonal Izquierda Abajo
                        if ((filaActual + 1 <= 10) && (columnaActual - 1 >= 0)) {
                            if (matriz[filaActual+1][columnaActual - 1] == '+') {
                                matriz[filaActual+1][columnaActual - 1] = '#';
                            }
                        }
                        //Diagonal Derecha Arriba
                        if ((filaActual - 1 >= 0) && (columnaActual + 1 <= 10)) {
                            if (matriz[filaActual-1][columnaActual + 1] == '+') {
                                matriz[filaActual-1][columnaActual + 1] = '#';
                            }
                        }
                        //Diagonal Derecha Abajo
                        if ((filaActual + 1 < 10) && (columnaActual + 1 <= 10)) {
                            if (matriz[filaActual + 1][columnaActual + 1] == '+') {
                                matriz[filaActual + 1][columnaActual + 1] = '#';
                            }
                        }
                    } else {
                        cout << "No puede saltar piezas. Turno perdido." << endl;
                    }
                }
            }//Fin del else
        }//Fin del if direccion 7
        if (direccion == 8) {
            if ((filaActual + espacios > 10) || (columnaActual + espacios > 10)) {
                cout << "Posicion invalida, pierde su turno." << endl;
            } else {
                if (espacios == 1) {
                    filaActual+=1;
                    columnaActual+=1;
                    if (matriz[filaActual][columnaActual] == ' ') {
                        filaActual--;
                        columnaActual--;
                        filaActual+=1;
                        columnaActual+=1;
                        matriz[filaActual][columnaActual] = '+';
                        //Arriba
                        if (filaActual - 1 >= 0) {
                            if (matriz[filaActual-1][columnaActual] == '+') {
                                matriz[filaActual-1][columnaActual] = '#';
                            }
                        }
                        //abajo
                        if (filaActual + 1 <= 10) {
                            if (matriz[filaActual+1][columnaActual] == '+') {
                                matriz[filaActual+1][columnaActual] = '#';
                            }
                        }
                        //Izquierda
                        if (columnaActual - 1 >= 0) {
                            if (matriz[filaActual][columnaActual-1] == '+') {
                                matriz[filaActual][columnaActual-1] = '#';
                            }
                        }
                        //Derecha
                        if (columnaActual + 1 <= 10) {
                            if (matriz[filaActual][columnaActual+1] == '+') {
                                matriz[filaActual][columnaActual+1] = '#';
                            }
                        }
                        //Diagonal Izquierda Arriba
                        if ((filaActual - 1 >= 0) && (columnaActual - 1 >= 0)) {
                            if (matriz[filaActual-1][columnaActual - 1] == '+') {
                                matriz[filaActual-1][columnaActual - 1] = '#';
                            }
                        }
                        //Diagonal Izquierda Abajo
                        if ((filaActual + 1 <= 10) && (columnaActual - 1 >= 0)) {
                            if (matriz[filaActual+1][columnaActual - 1] == '+') {
                                matriz[filaActual+1][columnaActual - 1] = '#';
                            }
                        }
                        //Diagonal Derecha Arriba
                        if ((filaActual - 1 >= 0) && (columnaActual + 1 <= 10)) {
                            if (matriz[filaActual-1][columnaActual + 1] == '+') {
                                matriz[filaActual-1][columnaActual + 1] = '#';
                            }
                        }
                        //Diagonal Derecha Abajo
                        if ((filaActual + 1 < 10) && (columnaActual + 1 <= 10)) {
                            if (matriz[filaActual + 1][columnaActual + 1] == '+') {
                                matriz[filaActual + 1][columnaActual + 1] = '#';
                            }
                        }
                    } else {
                        cout << "No puede saltar piezas. Turno perdido." << endl;
                    }
                }
                if (espacios == 2) {
                    filaActual+=2;
                    columnaActual+=2;
                    if (matriz[filaActual][columnaActual] == ' ') {
                        filaActual-=2;
                        columnaActual-=2;
                        filaActual+=espacios;
                        columnaActual+=espacios;
                        matriz[filaActual][columnaActual] = '+';
                        //Arriba
                        if (filaActual - 1 >= 0) {
                            if (matriz[filaActual-1][columnaActual] == '+') {
                                matriz[filaActual-1][columnaActual] = '#';
                            }
                        }
                        //abajo
                        if (filaActual + 1 <= 10) {
                            if (matriz[filaActual+1][columnaActual] == '+') {
                                matriz[filaActual+1][columnaActual] = '#';
                            }
                        }
                        //Izquierda
                        if (columnaActual - 1 >= 0) {
                            if (matriz[filaActual][columnaActual-1] == '+') {
                                matriz[filaActual][columnaActual-1] = '#';
                            }
                        }
                        //Derecha
                        if (columnaActual + 1 <= 10) {
                            if (matriz[filaActual][columnaActual+1] == '+') {
                                matriz[filaActual][columnaActual+1] = '#';
                            }
                        }
                        //Diagonal Izquierda Arriba
                        if ((filaActual - 1 >= 0) && (columnaActual - 1 >= 0)) {
                            if (matriz[filaActual-1][columnaActual - 1] == '+') {
                                matriz[filaActual-1][columnaActual - 1] = '#';
                            }
                        }
                        //Diagonal Izquierda Abajo
                        if ((filaActual + 1 <= 10) && (columnaActual - 1 >= 0)) {
                            if (matriz[filaActual+1][columnaActual - 1] == '+') {
                                matriz[filaActual+1][columnaActual - 1] = '#';
                            }
                        }
                        //Diagonal Derecha Arriba
                        if ((filaActual - 1 >= 0) && (columnaActual + 1 <= 10)) {
                            if (matriz[filaActual-1][columnaActual + 1] == '+') {
                                matriz[filaActual-1][columnaActual + 1] = '#';
                            }
                        }
                        //Diagonal Derecha Abajo
                        if ((filaActual + 1 < 10) && (columnaActual + 1 <= 10)) {
                            if (matriz[filaActual + 1][columnaActual + 1] == '+') {
                                matriz[filaActual + 1][columnaActual + 1] = '#';
                            }
                        }
                    } else {
                        cout << "No puede saltar piezas. Turno perdido." << endl;
                    }
                }
            }//Fin del else
        }//Fin del if direccion 8
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
