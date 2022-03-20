#include <iostream>
using namespace std;
#include "funciones.h"
#include "rlutil.h"


// SOLICITUDES:

int tipoCalculadora(){
    int calculadora;

    do {
    cout << endl << "�Cu�l es tu calculadora favorita?: \n";
    cout << endl << "     1 - CALCULADORA CLASICA ";
    cout << endl << "     2 - CALCULADORA CIENTIFICA \n";
    cout << endl << "Opci�n: ";
    cin >> calculadora;

        if (calculadora < 1 || calculadora > 2){
                 rlutil::cls();
                 rlutil::setColor(rlutil::RED);
                 cout<< endl << "Has elegido una opci�n inv�lida. Ingresa otra opci�n: ";
                 cout<< endl;
                 rlutil::setColor(rlutil::BLACK);
        }

    } while (calculadora < 1 || calculadora > 2);

    return calculadora;

}




void pideNombre (char nombre[]){

    cout << endl;
	cout << "    MATHRIX GAME     " << endl;
    cout<< "######################" << endl;
    cout << endl << "Ingrese su nombre: ";
    cin.ignore();
    cin.getline(nombre, 50);

        if(nombre[0]=='\0'){
        rlutil::setColor(rlutil::RED);
        cout<<"Ups! No has introducido tu nombre, ingresalo por favor: ";
        rlutil::setColor(rlutil::BLACK);
        cin.getline(nombre, 50);
    }


}



int cargarFila (){
    int f;
    cout << endl << endl << "Elige un n�mero e indica su fila y columna.";
    cout << endl << "Fila: ";
    cin >> f;

    while( f < 0 || f > 6){
    rlutil::setColor(rlutil::RED);
    cout<<"Has ingresado una fila fuera de rango, volv� a elegir: ";
    rlutil::setColor(rlutil::BLACK);
    cin >>f;
    }

    return f;

}

int cargarColumna(){
    int c;
    cout << "Columna: ";
    cin >> c;

     while(c<0 || c>6){
        rlutil::setColor(rlutil::RED);
        cout<<"Has ingresado una columna fuera de rango, volv� a elegir: ";
        cin >>c;
        rlutil::setColor(rlutil::BLACK);
    }

    return c;

}


int cargarDireccion(int f, int c){
    int dir;

    cout << endl << endl;
    cout << "�Genial! Ahora indicame la direcci�n en la que se encuenta el segundo n�mero: ";
    cout << endl <<"   Si queres que vaya ARRIBA, marc� 8";
    cout << endl <<"   Si queres que vaya ABAJO, marc� 2";
    cout << endl <<"   Si queres que vaya a la IZQUIERA, marc� 4";
    cout << endl <<"   Si queres que vaya a la DERECHA, marc� 6" << endl << "Direcci�n: ";
    cin >> dir;

    while (controlDir(dir)==false){
        rlutil::setColor(rlutil::RED);
        cout << endl << "OPCION INVALIDA: Elige una opci�n v�lida.";
        rlutil::setColor(rlutil::BLACK);
        cout << endl << endl<<"Ingresar direcci�n: ";
        cin >> dir;
    }

    // CONTROL DE QUE NO SALGA DE LOS BORDES DEL TABLERO:
    while (controlBordes( f , c , dir) == false){
        rlutil::setColor(rlutil::RED);
        cout << endl << "Opcion inv�lida: la opci�n elegida te har� salir del tablero. ";
        rlutil::setColor(rlutil::BLACK);
        cout << endl << endl<<"Ingresar direcci�n: ";
        cin >> dir;
    }

    return dir;

}

// Controla que no salgas de la matriz:

bool controlBordes (int f, int c, int d ) {

    // arriba 8, abajo 2 , izquierda 4 , derecha 6

   if ( (f <= 2 && d == 8) || (f >= 5 && d == 2) || (c <= 2 && d == 4) || (c >= 5 && d == 6) ){

    return false;

   } else {

        return true;
    }

}


// Controla que elija direcci�n v�lida:

bool controlDir (int dir){
    if (dir==8 || dir==2 || dir==4 || dir==6){
        return true;
    }
    else{
        return false;
    }
}



char cargarOperacion(){
    char op;

    cout << endl << endl;
    cout << "�Perfecto! Ahora decime qu� operaci�n queres realizar entre estos dos n�meros: ";
    cout << endl << "  Para SUMAR, marc� + ";
    cout << endl << "  Para RESTAR, marc� - ";
    cout << endl << "  Para DIVIDIR, marc� / ";
    cout << endl << "  Para MULTIPLICAR, marc� * ";
    cout << endl << "  Para el RESTO de divisi�n, marc� %";
    cout << endl <<"Operaci�n: ";
    cin >> op;

     while (op != '+' && op != '-' && op != '/' && op != '*' && op != '%')
    {
        rlutil::setColor(rlutil::RED);
        cout << endl << "Has seleccionado una operaci�n incorrecta " << endl << endl;
        rlutil::setColor(rlutil::BLACK);
        cout << "  Para SUMAR, marc� + ";
        cout << endl
             << "  Para RESTAR, marc� - ";
        cout << endl
             << "  Para DIVIDIR, marc� / ";
        cout << endl
             << "  Para MULTIPLICAR, marc� * ";
        cout << endl
             << "  Para el RESTO de divisi�n, marc� %";
        cout << endl
             << "Operaci�n: ";
        cin >> op;
    }


    return op;

}

