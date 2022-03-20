#include <iostream>
using namespace std;
#include "funciones.h"
#include "rlutil.h"


// SOLICITUDES:

int tipoCalculadora(){
    int calculadora;

    do {
    cout << endl << "¿Cuál es tu calculadora favorita?: \n";
    cout << endl << "     1 - CALCULADORA CLASICA ";
    cout << endl << "     2 - CALCULADORA CIENTIFICA \n";
    cout << endl << "Opción: ";
    cin >> calculadora;

        if (calculadora < 1 || calculadora > 2){
                 rlutil::cls();
                 rlutil::setColor(rlutil::RED);
                 cout<< endl << "Has elegido una opción inválida. Ingresa otra opción: ";
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
    cout << endl << endl << "Elige un número e indica su fila y columna.";
    cout << endl << "Fila: ";
    cin >> f;

    while( f < 0 || f > 6){
    rlutil::setColor(rlutil::RED);
    cout<<"Has ingresado una fila fuera de rango, volvé a elegir: ";
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
        cout<<"Has ingresado una columna fuera de rango, volvé a elegir: ";
        cin >>c;
        rlutil::setColor(rlutil::BLACK);
    }

    return c;

}


int cargarDireccion(int f, int c){
    int dir;

    cout << endl << endl;
    cout << "¡Genial! Ahora indicame la dirección en la que se encuenta el segundo número: ";
    cout << endl <<"   Si queres que vaya ARRIBA, marcá 8";
    cout << endl <<"   Si queres que vaya ABAJO, marcá 2";
    cout << endl <<"   Si queres que vaya a la IZQUIERA, marcá 4";
    cout << endl <<"   Si queres que vaya a la DERECHA, marcá 6" << endl << "Dirección: ";
    cin >> dir;

    while (controlDir(dir)==false){
        rlutil::setColor(rlutil::RED);
        cout << endl << "OPCION INVALIDA: Elige una opción válida.";
        rlutil::setColor(rlutil::BLACK);
        cout << endl << endl<<"Ingresar dirección: ";
        cin >> dir;
    }

    // CONTROL DE QUE NO SALGA DE LOS BORDES DEL TABLERO:
    while (controlBordes( f , c , dir) == false){
        rlutil::setColor(rlutil::RED);
        cout << endl << "Opcion inválida: la opción elegida te hará salir del tablero. ";
        rlutil::setColor(rlutil::BLACK);
        cout << endl << endl<<"Ingresar dirección: ";
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


// Controla que elija dirección válida:

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
    cout << "¡Perfecto! Ahora decime qué operación queres realizar entre estos dos números: ";
    cout << endl << "  Para SUMAR, marcá + ";
    cout << endl << "  Para RESTAR, marcá - ";
    cout << endl << "  Para DIVIDIR, marcá / ";
    cout << endl << "  Para MULTIPLICAR, marcá * ";
    cout << endl << "  Para el RESTO de división, marcá %";
    cout << endl <<"Operación: ";
    cin >> op;

     while (op != '+' && op != '-' && op != '/' && op != '*' && op != '%')
    {
        rlutil::setColor(rlutil::RED);
        cout << endl << "Has seleccionado una operación incorrecta " << endl << endl;
        rlutil::setColor(rlutil::BLACK);
        cout << "  Para SUMAR, marcá + ";
        cout << endl
             << "  Para RESTAR, marcá - ";
        cout << endl
             << "  Para DIVIDIR, marcá / ";
        cout << endl
             << "  Para MULTIPLICAR, marcá * ";
        cout << endl
             << "  Para el RESTO de división, marcá %";
        cout << endl
             << "Operación: ";
        cin >> op;
    }


    return op;

}

