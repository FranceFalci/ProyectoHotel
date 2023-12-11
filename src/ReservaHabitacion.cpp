/*
 * ReservaHabitacion.cpp
 *
 *  Created on: 29 nov. 2023
 *      Author: franc
 */

#include "ReservaHabitacion.h"
#include "Huesped.h"

int ReservaHabitacion::autonumerico = 0;

ReservaHabitacion::ReservaHabitacion(Fecha &fechaEntrada,Fecha &fechaSalida,int nroHabitacion){
	this->fechaEntrada = fechaEntrada;
	this->fechaSalida = fechaSalida;
	this->nroHabitacion = nroHabitacion;
	this->codigo = autonumerico++;
};

int ReservaHabitacion::getCodigo(){
	return codigo;
};

int ReservaHabitacion::getNroHabitacion(){
	return nroHabitacion;
};

Fecha ReservaHabitacion::getFechaSalida(){
	return fechaSalida;
};

Fecha ReservaHabitacion::getFechaEntrada(){
	return fechaEntrada;
};

int ReservaHabitacion::cantidadDias(){
	return (fechaSalida - fechaEntrada);
};

void ReservaHabitacion::agregarHuesped(string nombre, string dni){
	Huesped *huespedAcompaniante = new Huesped(nombre, dni, nroHabitacion);
	huespedes.push_back(huespedAcompaniante);
}

void ReservaHabitacion::agregarHuesped(string nombre,string apellido, string dni,string nacionalidad,string provincia,string mail,string domicilio,string patente,string telefono){
	Huesped *huespedTitular = new Huesped(nombre, apellido, nroHabitacion , dni, nacionalidad, provincia, mail, domicilio, patente, telefono);
	huespedes.push_back(huespedTitular);
}

void ReservaHabitacion::agregarConsumo(Consumo *consumo){
	consumos.push_back(consumo);
};

float ReservaHabitacion::calcularConsumo(){
	float total = 0 ;
	for(Consumo* consumo: consumos){
		total = total + consumo->getPrecio();
     }
	return total;
};

void ReservaHabitacion::listarInfo(){
	cout<<"\n";
	cout << "--------- Reserva: " << codigo << "---------" << endl;
	cout << "Numero de Habiacion: " << nroHabitacion << endl;
	cout << "Fecha de entrada: " << fechaEntrada << endl;
	cout << "Fecha de salida: " << fechaSalida << endl;
}

ReservaHabitacion::~ReservaHabitacion(){
	// TODO Auto-generated destructor stub
};



