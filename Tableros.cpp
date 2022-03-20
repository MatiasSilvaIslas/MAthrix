#include <iostream>
using namespace std;
#include "funciones.h"
#include "rlutil.h"


// TABLEROS:


void tableroMathrix ( int mat[][6] , int tam){

    int i, j, x=1;

    for ( i = 0 ; i < tam ; i++){
        for ( j= 0 ; j < tam ; j++){

            mat[i][j] = rand()%9;
        }
    }

// Este la muestra

    cout<<"     1"<<"  2"<<"  3"<<"  4"<<"  5"<<"  6"<<endl;
    cout<<"     ----------------"<<endl;
    for ( i = 0 ; i < tam ; i++){
        cout << " "<<x++<<"|  ";
        for ( j= 0 ; j < tam ; j++){
            cout << mat[i][j] << "  ";
        }
        cout<<endl;
    }
}

void tableroEnJuego (int mat[][6] , int tam){
    int i, j, x=1;

    cout<<"     1"<<"  2"<<"  3"<<"  4"<<"  5"<<"  6"<<endl;
    cout<<"     ----------------"<<endl;
    for ( i = 0 ; i < tam ; i++){
        cout << " "<<x++<<"|  ";
        for ( j= 0 ; j < tam ; j++){
            if ( mat[i][j] == -1 ){
                rlutil::setColor(rlutil::RED);
                cout << "X  ";
                rlutil::setColor(rlutil::BLACK);
            } else {
            cout << mat[i][j] << "  ";
            }
        }
        cout<<endl;
    }
}



void modificaTablero( int mat[][6], int tam, int f, int c, int dir ){
        f = f-1;
        c = c-1;
        mat[f][c] = -1; //CELDA 1

        switch(dir){
            case 8:
                mat[f-1][c] = -1; //CELDA 2
                mat[f-2][c] = -1; //CELDA 3
            break;

            case 2:
                mat[f+1][c] = -1; //CELDA 2
                mat[f+2][c] = -1; // CELDA 3
            break;

            case 4:
                mat[f][c-1] = -1; //CELDA 2
                mat[f][c-2] = -1; // CELDA 3
            break;

            case 6:
                mat[f][c+1] = -1; //CELDA 2
                mat[f][c+2] = -1; //CELDA 3
            break;
        }


}
