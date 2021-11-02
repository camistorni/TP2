#include "materiales.h"
#include "proceamiento.h"
#include <iostream>
#include <fstream>
#include <iomanip>

void leer_materiales(lista_materiales *lista){

	fstream archivo_materiales("materiales.txt", ios::in);
	
	lista->cantidad_materiales = 0;
	Material *material;
	string nombre, cantidad_material;
	
	while(archivo_materiales >> nombre){
		archivo_materiales >> cantidad_material;
		
		material = new Material;
		material->nombre_material = nombre;
		material->cantidad_material = stoi(cantidad_material);

		agregar_material(lista, material);

	}
	
	archivo_materiales.close();
}

void Ubicaciones::leer_ubicaciones(){

	fstream archivo_ubicaciones("ubicaciones.txt", ios::in);
	
	this->cantidad_ubicaciones = 0;
	Ubicacion *ubicacion;
	string nombre_edificio, fila, columna;
	string caracter;
	
	while(archivo_ubicaciones >> nombre_edificio){
		archivo_ubicaciones >> caracter; //Lee el espacio
		archivo_ubicaciones >> caracter; //Lee el paréntesis
		archivo_ubicaciones >> fila;
		archivo_ubicaciones >> caracter; //Lee la coma
		archivo_ubicaciones >> caracter; //Lee el espacio
		archivo_ubicaciones >> columna;
		archivo_ubicaciones >> caracter; //Lee el paréntesis
		
		ubicacion= new Ubicacion;
		ubicacion->nombre_edificio = nombre_edificio;
		ubicacion->fila = stoi(fila);
		ubicacion->columna = stoi(columna);
		
		agregar_ubicacion(ubicacion);
	}
	
	archivo_ubicaciones.close();
}

void Ubicaciones::agregar_ubicacion(Ubicacion *ubicacion){

	int n = this->cantidad_ubicaciones;
	Ubicacion **vector_ubicaciones = new Ubicacion*[n + 1];
	if(vector_ubicaciones == NULL)
		delete[] vector_ubicaciones;
	
	for(int i = 0; i < this->cantidad_ubicaciones; i++)
		vector_ubicaciones[i] = this->ubicacion[i];
		
	vector_ubicaciones[n] = ubicacion;
	
	if(this->cantidad_ubicaciones != 0){
		delete[] this->ubicacion;
	}
	
	this->ubicacion = vector_ubicaciones;
	this->cantidad_ubicaciones++;	

}

void cerrar_materiales(lista_materiales *lista){

	ofstream archivo_materiales("materiales.txt");
	
	for(int i = 0; i < lista->cantidad_materiales; i++){
		archivo_materiales << lista->material[i] -> nombre << ' '
						   << lista->material[i] -> cantidad_material << '\n';
		delete lista->material[i];
	}
	
	delete[] lista->material;
	lista->material = nullptr;
}

void Ubicaciones::cerrar_ubicaciones(){

	ofstream archivo_ubicaciones("ubicaciones.txt");
	
	for(int i = 0; i < cantidad_ubicaciones; i++){
		archivo_ubicaciones << this->ubicacion[i]->nombre_edificio << " ("
							<< this->ubicacion[i]->fila << ", "
							<< this->ubicacion[i]->columna << ')' << '\n';
	
		delete this->ubicacion[i];
	}
	delete[] this->ubicacion;
}

