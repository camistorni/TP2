#include "materiales.h"
#include "procesamiento.h"
#include <iostream>
#include <fstream>
#include <iomanip>

void Proceso::leer_materiales(){

	fstream archivo_materiales(PATH_MATERIALES, ios::in);
	
	this->cantidad_materiales = 0;
	Material *material;
	string nombre, cantidad_material;
	
	while(archivo_materiales >> nombre){
		archivo_materiales >> cantidad_material;
		
		material = new Material;
		material->nombre_material = nombre;
		material->cantidad_material = stoi(cantidad_material);

		//agregar_material(material);

	}
	
	archivo_materiales.close();
}

void Proceso::leer_opciones_edificios(){
	
	fstream archivo_edificios(PATH_EDIFICIOS, ios::in);
	
	this->cantidad_edificios = 0;
	Edificio *edificio;
	string nombre, cantidad_piedra, cantidad_madera, cantidad_metal, cantidad_maxima_permitida;
	
	while(archivo_edificios >> nombre){
		archivo_edificios >> cantidad_piedra;
		archivo_edificios >> cantidad_madera;
		archivo_edificios >> cantidad_metal;
		archivo_edificios >> cantidad_maxima_permitida;
		
		edificio = new Edificio;
		edificio->nombre_edificio = nombre;
		edificio->cantidad_piedra = stoi(cantidad_piedra);
		edificio->cantidad_madera = stoi(cantidad_madera);
		edificio->cantidad_metal = stoi(cantidad_metal);
		edificio->cantidad_maxima_permitida = stoi(cantidad_maxima_permitida);


		//agregar_edificio(edificio);

	}
	
	archivo_edificios.close();
}

void Proceso::leer_ubicaciones(){

	fstream archivo_ubicaciones(PATH_UBICACIONES, ios::in);
	
	this->cantidad_ubicaciones = 0;
	Ubicacion *ubicacion;
	string nombre_edificio;
	char caracter, fila, columna;
	
	while(archivo_ubicaciones >> nombre_edificio){
		archivo_ubicaciones >> caracter; //Lee el paréntesis
		archivo_ubicaciones >> fila;
		archivo_ubicaciones >> caracter; //Lee la coma
		archivo_ubicaciones >> columna;
		archivo_ubicaciones >> caracter; //Lee el paréntesis
		
		ubicacion= new Ubicacion;
		ubicacion->nombre_edificio = nombre_edificio;
		ubicacion->fila = fila - '0';
		ubicacion->columna = columna - '0';
		
		//agregar_ubicacion(ubicacion);
	}
	
	archivo_ubicaciones.close();
}

void Proceso::leer_mapa(int *cantidad_filas){

	fstream archivo_mapa(PATH_MAPA, ios::in);

	char filas, columnas;

	archivo_mapa >> filas;
	archivo_mapa >> columnas;

	cout << "fila: " << mapa->cantidad_filas << endl;
	cout << "columna: " << mapa->cantidad_columnas << endl;
		
	//Creación de la matriz dinámica
	mapa->mapa = new char * [filas - '0'];
	
	for(int i = 0; i < filas - '0'; i++)
		mapa->mapa[i] = new char[columnas - '0'];
	
	mapa->cantidad_filas = filas - '0';
	mapa->cantidad_columnas = columnas - '0';
	*cantidad_filas = filas- '0';
			
	//Inicialización de la matriz con los datos
	for(int i = 0; i < mapa->cantidad_filas; i++){
		for(int j = 0; j < mapa->cantidad_columnas; j++)
			mapa->mapa[i][j] = 0;
	}
	
	for(int i = 0; i < mapa->cantidad_filas; i++){
		for(int j = 0; j < mapa->cantidad_columnas; j++)
			archivo_mapa >> mapa->mapa[i][j];
	}
	
	archivo_mapa.close();
	
}

void Proceso::cerrar_materiales(){

	ofstream archivo_materiales(PATH_MATERIALES);
	
	for(int i = 0; i < this->cantidad_materiales; i++){
		archivo_materiales << this->material[i].nombre_material << ' '
						   << this->material[i].cantidad_material << '\n';
		//delete this->material[i];
	}
	
	delete[] this->material;
	this->material = nullptr;
}

void Proceso::cerrar_edificios(){

	ofstream archivo_edificios(PATH_EDIFICIOS);
	
	for(int i = 0; i < this->cantidad_edificios; i++){
		archivo_edificios << this->edificio[i].nombre_edificio << ' '
						  << this->edificio[i].cantidad_piedra << ' '
						  << this->edificio[i].cantidad_madera << ' '
						  << this->edificio[i].cantidad_metal << ' '
						  << this->edificio[i].cantidad_maxima_permitida << '\n';
//		delete this->edificio[i];

	}
	
	delete[] this->edificio;
	this->edificio = nullptr;
}

void Proceso::cerrar_ubicaciones(){

	ofstream archivo_ubicaciones(PATH_UBICACIONES);
	
	for(int i = 0; i < cantidad_ubicaciones; i++){
		archivo_ubicaciones << this->ubicacion[i].nombre_edificio << " ("
							<< this->ubicacion[i].fila << ", "
							<< this->ubicacion[i].columna << ')' << '\n';
	
		//delete this->ubicacion[i];
	}
	delete[] this->ubicacion;
}

