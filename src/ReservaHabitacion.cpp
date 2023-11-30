/*
 * ReservaHabitacion.cpp
 *
 *  Created on: 29 nov. 2023
 *      Author: franc
 */

#include "ReservaHabitacion.h"
#include "Huesped.h"

int ReservaHabitacion::autonumerico = 0;

int ReservaHabitacion::getCodigo(){
	return this->codigo;
};

int ReservaHabitacion::getNroHabitacion(){
	return this->nroHabitacion;
};

Fecha *ReservaHabitacion::getFechaSalida(){
	return this->fechaSalida;
};

Fecha *ReservaHabitacion::getFechaEntrada(){
	return this->fechaEntrada;
};

int ReservaHabitacion::cantidadDias(){
	return fechaEntrada->diferenciaEnDias(*fechaSalida);
};




void ReservaHabitacion::agregarHuesped(string nombre, string dni):Huesped(nombre,dni){};

void ReservaHabitacion::agregarHuesped(string nombre,string apellido, string dni,string nacionalidad,string provincia,string mail,string domicilio,string patente,string telefono):Huesped(nombre,apellido,nroHabitacion,dni,nacionalidad,provincia,mail,domicilio,patente,telefono){};

float ReservaHabitacion::calcularConsumo(){
	float total = 0 ;
	for(Consumo* consumo: consumos){
		total = total + consumo->getPrecio();
     }
	return total;
};

void ReservaHabitacion::agregarConsumo(Consumo *consumo){
	consumos.push_back(consumo);
};


ReservaHabitacion::ReservaHabitacion(Fecha *fechaEntrada,Fecha *fechaSalida,int nroHabitacion){
	this->fechaEntrada = fechaEntrada;
	this->fechaSalida = fechaSalida;
	this->nroHabitacion = nroHabitacion;
	this->codigo = ++this->autonumerico;
};

ReservaHabitacion::~ReservaHabitacion(){
	for(Consumo *consumo: consumos){
		delete consumo;
	}
	consumos.clear();

};



