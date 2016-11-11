#pragma once

class Tablero {
    private:
        char** matriz;
        int jugador;
    public:
        Tablero();
        void movimiento(int,int);
        void llenar();
        void imprimir();
        ~Tablero();
};
