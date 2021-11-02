#ifndef PROCESAMIENTO_H
#define PROCESAMIENTO_H

#include "materiales.h"
#include "edificios.h"
#include "ubicaciones.h"

#define PATH_MATERIALES "materiales.txt"
#define PATH_EDIFICIOS "edificios.txt"
#define PATH_UBICACIONES "ubicaciones.txt"
#define PATH_MAPA "mapa.txt"

using namespace std;

class Proceso{

	private:
		Material *material;
		Edificio *edificio
		Ubicacion *ubicacion;
		int cantidad_materiales, cantidad_edificio, cantidad_ubicaciones;
		
	public:
		//Precondiciones: -
		//Postcondiciones: Guarda los datos del archivo de materiales
		void leer_materiales(lista_materiales *lista);

		//Precondiciones: -
		//Postcondiciones: Guarda los datos del archivo de edificios
		void leer_opciones_edificios(lista_edificios *lista);

		void leer_ubicaciones();
		char **leer_mapa();

		//Precondiciones: -
		//Postcondiciones: Guarda los edificios en el archivo "edificios" y elimina la lista
		void cerrar_edificios(lista_edificios *lista);

		//Precondiciones: -
		//Postcondiciones: Guarda los materiales en el archivo "materiales" y elimina la lista
		void cerrar_materiales(lista_materiales *lista);
		
		void cerrar_ubicaciones();

		//Precondiciones: -
		//Postcondiciones: Guarda los edificios en el archivo "edificios" y elimina la lista. Guarda los materiales en el archivo "materiales" y elimina la lista
		void guardar_y_salir(lista_edificios *edificios, lista_materiales *materiales);
		
};

#endif
