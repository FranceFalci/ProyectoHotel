/*
 * Huesped.cpp
 *
 *  Created on: 29 nov. 2023
 *      Author: franc
 */

#include "Huesped.h"

Huesped::Huesped(string nombre, string dni) {
	this->nombre = nombre;
	this->dni = dni;
}
void Huesped::ListarInfo(){
	cout << "Nombre:" <<this->nombre<< endl;
	cout << "DNI:" <<this->dni<< endl;
};

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

Huesped::~Huesped() {
	// TODO Auto-generated destructor stub
}

