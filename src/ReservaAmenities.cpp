/*
 * ReservaAmenities.cpp
 *
 *  Created on: 29 nov. 2023
 *      Author: HP
 */

#include "ReservaAmenities.h"

ReservaAmenities::ReservaAmenities(Fecha &fecha, string hora, string dni, int nroHabitacion,string nombre) {
	this->fecha = fecha;
	this->hora = hora;
	this->dni = dni;
	this->nroHabitacion = nroHabitacion;
	this->nombreAmenities = nombre;
}

Fecha ReservaAmenities::getFecha(){
	return fecha;
}

string ReservaAmenities::getNombre(){
	return nombreAmenities;
}

string ReservaAmenities::getHora(){
	return hora;
}

ReservaAmenities::~ReservaAmenities() {
	// TODO Auto-generated destructor stub
}

