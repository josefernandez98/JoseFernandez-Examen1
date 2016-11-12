#pragma once

class Tablero {
    private:
        char** matriz;
        int jugador;
    public:
        Tablero();
        void movimiento(int,int, int);
        int verificarMatriz();
        void llenar();
        void imprimir();
        int verificacionFila(int);
        int verificacionColumna(int, int, int);
        ~Tablero();
};
