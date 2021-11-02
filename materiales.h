#ifndef MATERIALES_H
#define MATERIALES_H

#include <string>

using namespace std;

class Material{
	
	private:
		string nombre_material;
		int cantidad_material;
	
	public:
		//Precondiciones: -
		//Postcondiciones: Guarda los datos del archivo de materiales
		void leer_materiales(lista_materiales *lista);
		
		//Precondiciones: Se tiene que haber leído bien el archivo de materiales
		//Postcondiciones: Agrega el material leído a la lista de materiales disponibles
		void agregar_material(lista_materiales *lista, material_t *material);

		//Precondiciones: -
		//Postcondiciones: Imprime los materiales disponibles
		void listar_materiales(lista_materiales *lista);

		//Precondiciones: -
		//Postcondiciones: Verifica que haya la sufuciente cantidad de materiales para construir un edificio especifico
		bool verificar_materiales(lista_materiales *materiales, string nombre_ingresado, int piedra_necesaria, int madera_necesaria, int metal_necesario, int construidos, int cantidad_max);
};

struct lista_materiales{
	Material **material;
	int cantidad_materiales;
};

#endif
