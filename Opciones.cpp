#include <iostream>
using namespace std;
#include "funciones.h"
#include "rlutil.h"


// OPCIONES:

int opciones (){

    int opcion;

    do {
        cout << endl ;
        cout << "       MATHRIX" << endl;
        cout << "------------------------" << endl;
        cout << "   1 - JUGAR" << endl;
        cout << "   2 - ESTADISTICAS" << endl;
        cout << "   3 - CREDITOS" << endl;
        cout << "   4 - INSTRUCCIONES" << endl;
        cout << "------------------------" << endl;
        cout << "   0 - SALIR" << endl;
        cout << endl << endl << "Opción: ";
        cin >> opcion;

        } while (controlopciones(opcion) == false);

    return opcion;

}


bool controlopciones (int opcion) {

    // Opciones posibles: 0 , 1, 2, 3, 4.

   if ( opcion == 0 || opcion == 1 || opcion == 2 || opcion == 3 || opcion == 4 ){

    return true;

   } else {
        rlutil::cls();
        rlutil::setColor(rlutil::RED);
        cout << endl << "Opción inválida. Por favor elige otra opción: ";
        cout << endl << endl;
        rlutil::setColor(rlutil::BLACK);
        return false;
    }

}




void estadisticas(char maxNombre[], int puntajeAcumulado){
    rlutil::setBackgroundColor(rlutil::YELLOW);
    rlutil::cls();
    cout << endl;
    cout << "<<ESTADISTICAS>> \n";
    cout << endl << "Mejor puntaje: " << maxNombre << " con " << puntajeAcumulado << " puntos. ";
    cout<<endl<<endl<<endl<<"Presiona cualquier tecla para continuar: ";
    rlutil::anykey();
    rlutil::cls();
    rlutil::setBackgroundColor(rlutil::GREY);

}


void creditos(){
    rlutil::setBackgroundColor(rlutil::BLUE);
    rlutil::setColor(rlutil::WHITE);
    rlutil::cls();
    cout << endl << endl;
    cout << "           CREDITOS           " << endl;
    cout << "##############################" << endl;
    cout << "-- Menos de un minuto GAMES --" << endl;
    cout << "..............................." <<endl << endl;
    cout << endl << "STAFF: \n";
    cout << endl << "Fernandez, Cecilia, 25124." << endl;
    cout << "Silva Islas, Matias Nicolas, 23635." << endl;
    cout << "Aquino, Agustín, 24462." << endl;
    cout<<endl<<endl<<"Adaptación del juego Mathrix - piecepack game creado por Clark D. Rodeffer.";
    cout<<endl<<endl<<endl<<"Presiona cualquier tecla para continuar: ";
    rlutil::anykey();
    rlutil::cls();
    rlutil::setColor(rlutil::BLACK);
    rlutil::setBackgroundColor(rlutil::GREY);

}

void instrucciones(){
    rlutil::setBackgroundColor(rlutil::BROWN);
    rlutil::cls();
    cout<<endl<<"                               ¡Bienvenid@ a MATHRIX! \n";
    cout<<      "                    ************************************************* \n";
    cout<<endl<<" El objetivo del juego es elegir un número de la matriz (seleccionando la fila y la columna) \n";
    cout<<      " y otro número contiguo a este (arriba, abajo, a la izquiera o a la derecha). \n";
    cout<<      " Luego deberás realizarles una operación matemática: sumar (+), restar (-), multiplicar (*), \n";
    cout<<      " dividir (/) o calcular el resto (%) de la division. Si el resultado es igual al número \n";
    cout<<      " siguiente en la dirección seleccionada,la suma de estos tres números sera tu puntaje! \n";
    cout<<endl<<" TENE CUIDADO CON: \n";
    cout<<endl<<"                  *Elegir celdas que no den el resultado de tu operación matemática.";
    cout<<endl<<"                  *Elegir una direccion que te lleve a atravesar una terna bloqueada.";
    cout<<endl<<endl<<" Hacer cualquiera de estas cosas hará que tu calculadora pierda una pila ¡Y solo tenes tres!";
    cout<<endl<<endl<<endl<<" Ahora si, ¡ A jugar !"<< endl << endl;
    cout<<endl<<endl<<endl <<" Presiona cualquier tecla para continuar: ";
    rlutil::anykey();
    rlutil::cls();
    rlutil::setBackgroundColor(rlutil::GREY);

}

void opcion0(int puntajeAcumulado){

        if ( puntajeAcumulado == 0){

            rlutil::cls();
            cout << endl << endl << endl << endl;
            cout << "                  ¡Hasta luego!";

        } else {
            rlutil::cls();
            cout << endl << endl << endl << endl;
            cout << "                  ¡Gracias por jugar Mathrix! " << endl;
        }
}
