#include <iostream>
using namespace std;
#include "funciones.h"
#include "rlutil.h"

// CALCULADORAS:


int jugarCLASICA(int puntajeAcumulado, char maxNombre[])
{
    rlutil::setBackgroundColor(rlutil::CYAN);
    rlutil::cls();
    int f, c, dir, tablero[6][6], ronda, pilas;
    int celda1, celda2, celda3, puntajeTotal;
    char op, nombre [50];

    ronda = 0, pilas = 3, puntajeTotal = 0;
    pideNombre(nombre);
    rlutil::cls();
    while(pilas>0)
    {

        ronda++;
        if ( ronda == 1 )
        {
            cout << endl;
            cout << "    MATHRIX GAME     " << endl;
            cout << "######################" << endl << endl;
            cout << "¡Bienvenid@ "<< nombre<< "!";
            cout << endl << endl << "       ¡Calculadora Clásica!";
            cout << endl <<         "----------------------------------";
            cout << endl << endl << "Esta es la ronda número " << ronda;
            cout << endl << "Tenes " << pilas << " pilas!";
            cout << endl << "Y tus puntos hasta ahora son: " << puntajeTotal << " puntos!";
            cout << endl << endl << "¡Vamos a jugar!" << endl << "Aca tenes tu tablero: ";
            cout << endl << endl;
            tableroMathrix ( tablero, 6);

        }
        else
        {
            cout << endl << endl << "Esta es la ronda número " << ronda;
            if (pilas == 1 )
            {
                rlutil::setColor(rlutil::LIGHTMAGENTA);
                cout << endl << "¡¡ Te queda la última pila !!";
                rlutil::setColor(rlutil::BLACK);
            }
            else
            {
                cout << endl << "Tenes " << pilas << " pilas!";
            }
            cout << endl << "Y tus puntos hasta ahora son: " << puntajeTotal << " puntos!";
            cout << endl << endl << "¡Próximo intento!" << endl << "Aca tenés tu tablero: " << endl<<endl;
            tableroEnJuego (tablero, 6);

        }

        //Elige coordenadas:

        f = cargarFila();
        c = cargarColumna();
        if(c==0 && f==0)
        {
            tableroMathrix ( tablero, 6);
            rlutil::cls();
            rlutil::setColor(rlutil::RED);
            cout<<"Has seleccionado fila 0 y columna 0, esto te resta una pila";
            rlutil::setColor(rlutil::BLACK);
            pilas--;
        }
        else
        {
            if(c==0 || f==0)
            {
                rlutil::setColor(rlutil::RED);
                cout<<endl<<"Has ingresado una fila o columna incorrecta, volve a ingresarlas"<<endl;
                rlutil::setColor(rlutil::BLACK);
                f = cargarFila();
                c = cargarColumna();
                dir = cargarDireccion(f, c);
                op = cargarOperacion();
                celda1 = c1(tablero, 6, f, c);
                celda2 = c2(tablero, 6, f, c, dir);
                celda3 = c3(tablero, 6, f, c, dir);
            }
            else
            {
                dir = cargarDireccion(f, c);
                op = cargarOperacion();
                celda1 = c1(tablero, 6, f, c);
                celda2 = c2(tablero, 6, f, c, dir);
                celda3 = c3(tablero, 6, f, c, dir);
            }


            //Analiza  si acertó o que no haya pasado por celdas bloqueadas:
            bool r = false;

            if (celda1== -1 || celda2 == -1 || celda3 == -1)
            {
                cout << endl << endl << endl;
                rlutil::setColor(rlutil::RED);
                cout << " ¡Ups! Has seleccionado una celda inválida y te resta una pila :( ";
                cout << endl << endl << endl;
                pilas--;
                rlutil::setColor(rlutil::BLACK);

            }
            else
            {

                r = operaciones(celda1, celda2, celda3, op);

                if( r == true)
                {
                    puntajeTotal += puntos(celda1, celda2, celda3);
                    modificaTablero(tablero, 6, f, c, dir);
                    rlutil::cls();
                    cout << endl << "¡Pefecto! ¡Le atinaste!";
                    cout << endl << "SIGAMOS" << endl << endl;
                }
                else
                {
                    pilas--;
                    cout << endl << endl << endl;
                    rlutil::setColor(rlutil::RED);
                    cout << "¡Ups! El resultado no es correcto y restas una pila :(";

                    rlutil::setColor(rlutil::BLACK);
                    cout << endl << endl << endl;
                }
            }
        }
    }




    // PILAS == 0 ---> compara puntajeTotal con Acumulado para ver cual es el mayor:
    if ( puntajeTotal > puntajeAcumulado)
    {
        puntajeAcumulado = puntajeTotal;
        strcpy ( maxNombre, nombre ); // Asigna nombre en maxNombre
    }

    cout << endl << endl;
    cout << endl << "  Te quedaste sin pilas :(";
    cout << endl << "  Tu puntaje final: " << puntajeTotal << " puntos. ";
    if ( puntajeAcumulado > 0)
    {
        cout << endl << "  Mejor puntaje: " << maxNombre << " con " << puntajeAcumulado << " puntos. ";
    }
    cout << endl;
    cout << endl << " -------------------------------------- ";
    cout << endl << endl;
    cout<<endl<<endl<<endl<<"Presiona cualquier tecla para continuar: "<<endl<<endl;
    rlutil::anykey();
    rlutil::setBackgroundColor(rlutil::GREY);
    return puntajeAcumulado;
}



int jugarCIENTIFICA(int puntajeAcumulado, char maxNombre[])
{
    rlutil::setBackgroundColor(rlutil::LIGHTCYAN);
    rlutil::cls();
    int f, c, dir, tablero[6][6], ronda, pilas;
    int celda1, celda2, celda3, puntajeTotal;
    char op, nombre [50];

    ronda = 0, pilas = 3, puntajeTotal = 0;
    pideNombre(nombre);
    rlutil::cls();
    while(pilas>0)
    {

        ronda++;
        if ( ronda == 1 )
        {
            cout << endl;
            cout << "    MATHRIX GAME     " << endl;
            cout << "######################" << endl << endl;
            cout << "¡Bienvenid@ "<< nombre<< "!";
            cout << endl << endl << "       ¡Calculadora Científica!";
            cout << endl <<         "----------------------------------";
            cout << endl << endl << "Esta es la ronda número " << ronda;
            cout << endl << "Tenes " << pilas << " pilas!";
            cout << endl << "Y tus puntos hasta ahora son: " << puntajeTotal << " puntos!";
            cout << endl << endl << "¡Vamos a jugar!" << endl << "Aca tenes tu tablero: ";
            cout << endl << endl;
            tableroMathrix ( tablero, 6);

        }
        else
        {
            cout << endl << endl << "Esta es la ronda número " << ronda;
            if (pilas == 1 )
            {
                rlutil::setColor(rlutil::LIGHTMAGENTA);
                cout << endl << "¡¡ Te queda la última pila !!";
                rlutil::setColor(rlutil::BLACK);
            }
            else
            {
                cout << endl << "Tenes " << pilas << " pilas!";
            }
            cout << endl << "Y tus puntos hasta ahora son: " << puntajeTotal << " puntos!";
            cout << endl << endl << "¡Próximo intento!" << endl << "Aca tenés tu tablero: " << endl<<endl;
            tableroEnJuego (tablero, 6);

        }

        //Elige coordenadas:

        f = cargarFila();
        c = cargarColumna();
        dir = cargarDireccion(f, c);
        op = cargarOperacion();

        celda1 = c1(tablero, 6, f, c);
        celda2 = c2(tablero, 6, f, c, dir);
        celda3 = c3(tablero, 6, f, c, dir);

        //Analiza  si acertó o que no haya pasado por celdas bloqueadas:
        bool r = false;

        if (celda1== -1 || celda2 == -1 || celda3 == -1)
        {
            cout << endl << endl << endl;
            rlutil::setColor(rlutil::RED);
            cout << " ¡Ups! Has seleccionado una celda inválida y te resta una pila :( ";
            cout << endl << endl << endl;
            pilas--;
            rlutil::setColor(rlutil::BLACK);

        }
        else
        {

            r = operaciones(celda1, celda2, celda3, op);

            if( r == true)
            {
                puntajeTotal += puntos(celda1, celda2, celda3);
                modificaTablero(tablero, 6, f, c, dir);
                rlutil::cls();
                cout << endl << "¡Pefecto! ¡Le atinaste!";
                cout << endl << "SIGAMOS" << endl << endl;
            }
            else
            {
                pilas--;
                cout << endl << endl << endl;
                rlutil::setColor(rlutil::RED);
                cout << "¡Ups! El resultado no es correcto restas una pila :(";

                rlutil::setColor(rlutil::BLACK);
                cout << endl << endl << endl;
            }
        }

    }

    // PILAS == 0 ---> compara puntajeTotal con Acumulado para ver cual es el mayor:
    if ( puntajeTotal > puntajeAcumulado)
    {
        puntajeAcumulado = puntajeTotal;
        strcpy ( maxNombre, nombre ); // Asigna nombre en maxNombre
    }

    cout << endl << endl;
    cout << endl << "  Te quedaste sin pilas :(";
    cout << endl << "  Tu puntaje final: " << puntajeTotal << " puntos. ";
    if ( puntajeAcumulado > 0)
    {
        cout << endl << "  Mejor puntaje: " << maxNombre << " con " << puntajeAcumulado << " puntos. ";
    }
    cout << endl;
    cout << endl << " -------------------------------------- ";
    cout << endl << endl;
    cout<<endl<<endl<<endl<<"Presiona cualquier tecla para continuar: "<<endl<<endl;
    rlutil::anykey();
    rlutil::setBackgroundColor(rlutil::GREY);
    return puntajeAcumulado;
}
