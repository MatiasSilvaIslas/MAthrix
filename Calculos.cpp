#include <iostream>
using namespace std;
#include "funciones.h"
#include "rlutil.h"



// CALCULOS:

    int c1 (int tablero[][6], int tam, int f, int c){
        int celda1;
        f = f-1;
        c = c-1;

        celda1 = tablero[f][c];

        return celda1;
    }

    int c2 (int tablero[][6], int tam, int f, int c, int dir){
        int celda2;
        f = f-1;
        c = c-1;

        switch(dir){
            case 8:
                celda2 = tablero[f-1][c];
            break;

            case 2:
                celda2 = tablero [f+1][c];
            break;

            case 4:
                celda2 = tablero [f][c-1];
            break;

            case 6:
                celda2 = tablero [f][c+1];
            break;
        }


        return celda2;
    }


int c3 (int tablero[][6], int tam, int f, int c, int dir){
        int celda3;
        f = f-1;
        c = c-1;

        switch(dir){
            case 8:
                celda3 = tablero[f-2][c];
            break;

            case 2:
                celda3 = tablero[f+2][c];
            break;

            case 4:
                celda3 = tablero[f][c-2];
            break;

            case 6:
                celda3 = tablero[f][c+2];
            break;
        }

        return celda3;
}



//La que realiza las operaciones aritmeticas:

bool operaciones(int celda1, int celda2, int celda3, char op){
    float r;
    switch (op){
        case '+': r = celda1 + celda2;
                    if(r == celda3){
                        return true;
                    }

        break;
        case '-': r = celda1 - celda2;
                    if(r == celda3){
                        return true;
                    }

        break;
        case '*': r = celda1 * celda2;
                    if(r == celda3){
                        return true;
                    }

        break;
        case '/': r = celda1/celda2;
                    if(r == celda3){
                        return true;
                    }

        break;
        case '%': r = celda1 % celda2;
                    if(r == celda3){
                        return true;
                    }

        break;
    }
    return false;
}



//La que suma puntos:

int puntos(int celda1, int celda2, int celda3){
int dev = 0, puntos;
    puntos = celda1 + celda2 + celda3;
    dev += puntos;

	return dev;
}
