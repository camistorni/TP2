#ifndef PROCESAMIENTO_H
#define PROCESAMIENTO_H

#include "materiales.h"
#include "edificios.h"

using namespace std;

//Precondiciones: -
//Postcondiciones: Guarda los datos del archivo de materiales
void leer_materiales(lista_materiales *lista);

//Precondiciones: -
//Postcondiciones: Guarda los datos del archivo de edificios
void leer_opciones_edificios(lista_edificios *lista);

//Precondiciones: -
//Postcondiciones: Guarda los edificios en el archivo "edificios" y elimina la lista
void cerrar_edificios(lista_edificios *lista);

//Precondiciones: -
//Postcondiciones: Guarda los materiales en el archivo "materiales" y elimina la lista
void cerrar_materiales(lista_materiales *lista);

//Precondiciones: -
//Postcondiciones: Guarda los edificios en el archivo "edificios" y elimina la lista. Guarda los materiales en el archivo "materiales" y elimina la lista
void guardar_y_salir(lista_edificios *edificios, lista_materiales *materiales);

#endif
