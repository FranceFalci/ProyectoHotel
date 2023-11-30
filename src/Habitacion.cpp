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
    int cantidad = buscarReserva(nroReserva)->cantidadDias();
    return calcularCostoPorNoche()*cantidad;
}

void Habitacion::listarInfo(){
    std::cout << "Número de Habitación: " << nroHabitacion << std::endl;
    std::cout << "Número de Camas: " << nroCamas << std::endl;
    std::cout << "Capacidad: " << capacidad << std::endl;
    std::cout << "Precio Base: " << precioBase << std::endl; 
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
    ReservaHabitacion *reserva= new ReservaHabitacion(fechaEntrada, fechaSalida, this->nroHabitacion);
    Reservas.push_back(reserva);
    
    // Obtén el índice de la última reserva
    int indiceReserva = Reservas.size() - 1;
    // Agrega al huésped a la última reserva
    Reservas[indiceReserva]->agregarHuesped(nombre, apellido, dni, nacionalidad, provincia, mail, domicilio, patente, telefono);  //Da error por el momento porque no esta implementad el metodo agregarHuesped
}

void Habitacion::agregarHuesped(string nombre, string dni, int nroReserva) {
    ReservaHabitacion* reserva = buscarReserva(nroReserva);
    if (reserva) {
        reserva->agregarHuesped(nombre, dni);
    } else {
        std::cout << "La reserva no fue encontrada." << std::endl;
    }
}

void Habitacion::agregarHuesped(string nombre, string apellido, string dni, string nacionalidad, string provincia, string mail, string domicilio, string patente, string telefono, int nroReserva) {
    ReservaHabitacion* reserva = buscarReserva(nroReserva);

    if (reserva) {
        reserva->agregarHuesped(nombre, apellido, dni, nacionalidad, provincia, mail, domicilio, patente, telefono);
    } else {
        // Manejar el caso cuando la reserva no se encuentra
        // Puedes imprimir un mensaje, lanzar una excepción, etc.
        std::cout << "La reserva no fue encontrada." << std::endl;
    }
}


float Habitacion::calcularCostoTotalReserva(int nroReserva) {
    ReservaHabitacion* reserva = buscarReserva(nroReserva);
    if (reserva) {
        int cantidadDias = reserva->cantidadDias();
        return calcularCostoPorNoche() * cantidadDias;
    } else {
        // Manejar el caso cuando la reserva no se encuentra
        return 0.0; // O cualquier valor predeterminado
    }
}



ReservaHabitacion* Habitacion::buscarReserva(int nroReserva) {
    for (ReservaHabitacion*& reserva : Reservas) {
        if (reserva->getCodigo() == nroReserva) {
            return reserva;
        }
    }
    // Si no se encuentra la reserva, devolver un puntero nulo.
    return nullptr;
}

/* bool Habitacion::estaDisponible(Fecha fechaInicio, Fecha fechaFin) {
    for (ReservaHabitacion*& reserva : Reservas) {
        if (fechaFin <= reserva->getFechaEntrada() || fechaInicio >= reserva->getFechaSalida()) { //sonsultar mas tarde
            return false;
        }
    }
    return true;
} */

bool Habitacion::estaDisponible(Fecha* fechaInicio, Fecha* fechaFin) {
    for (ReservaHabitacion*& reserva : Reservas) {
        if (!(fechaFin <= reserva->getFechaEntrada() || fechaInicio >= reserva->getFechaSalida())) {
            return false;
        }
    }
    return true;
}
