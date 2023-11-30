#include "Habitacion.h"
#include <iostream>
int Habitacion::autonumerico = 1;

Habitacion::Habitacion(int nroCamas, int capacidad, float precioBase) {
	this->nroHabitacion=autonumerico++;
    this->nroCamas=nroCamas;
    this->capacidad=capacidad;
    this->precioBase=precioBase;
    this->Reservas = {};
}

Habitacion::~Habitacion() {
	// TODO Auto-generated destructor stub
}

float Habitacion::calcularCostoPorNoche(){
    return this->capacidad*this->precioBase;
}

float Habitacion::calcularCostoTotalReserva(int nroReserva){
    int cantidad = buscarReserva(nroReserva).CantidadDias();
    return calcularCostoPorNoche()*cantidad;
}

void Habitacion::listarInfo(){
    std::cout <<"codigo: "<< codigo << std::endl; 
    std::cout <<"nombre: "<< nombre << std::endl; 
    std::cout <<"precio: "<< precio << std::endl; 
}

int Habitacion::getCodigo(){
    return nroHabitacion;
}

int Habitacion::getCapacidad(){
	return capacidad;
}

float Habitacion::getSenia(int nroReserva){
    return calcularCostoTotalReserva(nroReserva)*0.3;
}

void Habitacion::crearReserva(Fecha &fechaEntrada, Fecha &fechaSalida, string nombre,string apellido,string dni,string nacionalidad,string provincia,string mail,string domicilio,string patente,string telefono){
    ReservaHabitacion *reserva= new ReservaHabitacion(fechaEntrada, fechaSalida, this->nroHabitacion)
    Reservas.push(reserva);
    Reservas
}
