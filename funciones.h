#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED


// CALCULOS
int c1 (int [][6] , int,  int, int);
int c2 (int [][6] , int,  int, int, int);
int c3 (int [][6] , int,  int, int, int);
bool operaciones(int, int, int, char);
int puntos(int, int, int);


// OPCIONES
int opciones ();
bool controlopciones ( int );
void estadisticas(char[], int);
void creditos();
void instrucciones();
void opcion0(int);

// SOLICITUDES
int tipoCalculadora();
void pideNombre (char[]);
int cargarFila();
int cargarColumna();
int cargarDireccion(int, int);
bool controlBordes ( int , int , int );
bool controlDir (int);
char cargarOperacion();


// CALCULADORA
int jugarCLASICA(int, char[]);
int jugarCIENTIFICA(int, char[]);

// TABLEROS
void tableroMathrix (int [][6] , int);
void tableroEnJuego (int [][6] , int);
void modificaTablero(int[][6], int, int, int,int);


#endif // FUNCIONES_H_INCLUDED
