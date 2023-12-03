/*
 * Huesped.cpp
 *
 *  Created on: 29 nov. 2023
 *      Author: franc
 */

#include "Huesped.h"

Huesped::Huesped(string nombre, string dni, int nroHabitacion) {
	this->nombre = nombre;
	this->dni = dni;
    this->nroHabitacion = nroHabitacion;
}

Huesped::Huesped(string nombre, string apellido, int nroHabitacion, string dni, string nacionalidad, string provincia, string mail, string domicilio, string patente, string telefono) {
    this->nombre = nombre;
    this->apellido = apellido;
    this->nroHabitacion = nroHabitacion;
    this->dni = dni;
    this->nacionalidad = nacionalidad;
    this->provincia = provincia;
    this->mail = mail;
    this->domicilio = domicilio;
    this->patente = patente;
    this->telefono = telefono;
}

void Huesped::ListarInfo(){
	cout << "Nombre:" <<nombre<< endl;
	cout << "DNI:" <<dni<< endl;
};

string Huesped::getDNI(){
	return dni;
};

string Huesped::getNombre(){
	return nombre;
};


Huesped::~Huesped() {
	// TODO Auto-generated destructor stub
}

