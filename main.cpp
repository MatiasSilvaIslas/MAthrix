#include <iostream>
#include <ctime>
#include "funciones.h"
#include "rlutil.h"
using namespace std;

/*Apellidos M (inclusive) - Z (inclusive) : Al ingresar las coordenadas de matriz 0,0 se pierde una pila pero se aleatoriza
nuevamente toda la matriz.
*/

int main(){
  	srand (time(NULL)) ;
	setlocale(LC_CTYPE, "Spanish");

	int opcion, puntajeAcumulado = 0, calculadora;
	char maxNombre[50], salir = 'N';

    cout<<endl<<endl;
    cout<<endl<<"                               ¡Bienvenid@ a MATHRIX! \n";
    cout<<      "                    ************************************************* \n";
    cout<<endl<<endl<<endl<<" Presiona cualquier tecla para continuar: ";
    rlutil::anykey();

    rlutil::setBackgroundColor(rlutil::GREY);
    rlutil::setColor(rlutil::BLACK);

    while (salir == 'N'){
    rlutil::cls();
	opcion = opciones();

	while ( opcion == 2 && puntajeAcumulado == 0) {

        rlutil::cls();
        rlutil::setBackgroundColor(rlutil::YELLOW);
        cout << endl << "Aún no hay estadísticas. Elige otra opción: ";
        cout << endl << endl << endl;
        rlutil::setBackgroundColor(rlutil::GREY);
        opcion = opciones();
	}


	switch (opcion){
        case 1:
                calculadora = tipoCalculadora();

                if( calculadora == 1 ){
                    puntajeAcumulado = jugarCLASICA(puntajeAcumulado, maxNombre);
                    }

                else {
                        puntajeAcumulado = jugarCIENTIFICA(puntajeAcumulado, maxNombre);
                        }
        break;
        case 2:
                estadisticas(maxNombre, puntajeAcumulado);
        break;
        case 3:
                creditos();

        break;
        case 4:
                instrucciones();
        break;
        case 0:
                rlutil::setColor(rlutil::LIGHTRED);
                cout << endl << "¿ Estás segur@ que queres salir ? ( S / N )  ";
                rlutil::setColor(rlutil::BLACK);
                cin >> salir;
                salir = toupper(salir); // Para convertirla a mayuscula si ingresa minuscula
                if ( salir == 'S' ){
                    opcion0(puntajeAcumulado);
                }
        break;
        }
        cout << endl << endl;

    }

	cout << endl;

	return 0;
}
