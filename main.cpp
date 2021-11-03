#include "materiales.h"
#include "edificios.h"
#include "ubicaciones.h"
#include "procesamiento.h"


int main(){

	Proceso *proceso = new Proceso;
	proceso->material = new Material * [1];
	proceso->edificio = new Edificio * [1];
	proceso->ubicacion = new Ubicacion * [1];
	proceso->mapa = new Mapa;
	int cantidad_filas;
	
	proceso->leer_materiales();
	proceso->leer_opciones_edificios();
	proceso->leer_ubicaciones();
	proceso->leer_mapa(&cantidad_filas);
	
	cout << "todo ok" << endl;
	
	/*for(int i = 0; i < cantidad_filas; i++){
		delete proceso->mapa->mapa[i];
	}
	delete[] poceso->mapa->mapa;*/
	
	proceso->cerrar_materiales();
	proceso->cerrar_edificios();
	proceso->cerrar_ubicaciones();
	
	return 0;
}
