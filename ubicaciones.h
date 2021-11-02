#ifndef UBICACIONES_H
#define UBICACIONES_H

#include <string>

using namespace std;

class Ubicacion{
	public:
		string nombre_edificio;
		int fila;
		int columna;
};

class Ubicaciones{

	private:
		Ubicacion **ubicacion;
		int cantidad_ubicaciones;
		
	public:
		void leer_ubicaciones();
		void cerrar_ubicaciones();
		void agregar_ubicacion(Ubicacion *ubicacion);
};

#endif
