#include "Habitacion.h"
int Habitacion::autonumerico = 1;

Habitacion::Habitacion(int nroCamas, int capacidad, float precioBase) {
	this->nroHabitacion = autonumerico++;
    this->nroCamas = nroCamas;
    this->capacidad = capacidad;
    this->precioBase = precioBase;
    this->Reservas = {};
}


float Habitacion::calcularCostoPorNoche(){
    return (capacidad*precioBase);
}

float Habitacion::calcularCostoTotalReserva(int nroReserva){
	ReservaHabitacion* reserva = buscarReserva(nroReserva);
	int cantidadDias = reserva->cantidadDias();

	return calcularCostoPorNoche() * cantidadDias;
}

/*float Habitacion::calcularCostoTotalReserva(int nroReserva){
    int cantidad = buscarReserva(nroReserva)->cantidadDias();
    return calcularCostoPorNoche()*cantidad;
}*/

int Habitacion::getCodigo(){
    return nroHabitacion;
}

int Habitacion::getCapacidad(){
	return capacidad;
}

float Habitacion::getSenia(int nroReserva){
    return calcularCostoTotalReserva(nroReserva)*0.3;
}

void Habitacion::crearReserva(Fecha *fechaEntrada, Fecha *fechaSalida, string nombre,string apellido,string dni,string nacionalidad,string provincia,string mail,string domicilio,string patente,string telefono){
    ReservaHabitacion *reserva= new ReservaHabitacion(fechaEntrada, fechaSalida, nroHabitacion);
    reserva->agregarHuesped(nombre, apellido, dni, nacionalidad, provincia, mail, domicilio, patente, telefono);
    Reservas.push_back(reserva);
    
    /*// Obtén el índice de la última reserva
    int indiceReserva = Reservas.size() - 1;
    // Agrega al huésped titular a la última reserva
    Reservas[indiceReserva]->agregarHuesped(nombre, apellido, dni, nacionalidad, provincia, mail, domicilio, patente, telefono);  //Da error por el momento porque no esta implementad el metodo agregarHuesped*/
}

bool Habitacion::estaDisponible(Fecha *fechaInicio, Fecha *fechaFin){
	for (size_t i = 0; i < Reservas.size(); ++i) {
		if (!(fechaFin <= Reservas[i]->getFechaEntrada() || fechaInicio >= Reservas[i]->getFechaSalida())) {
			return false;
		}
	}
	return true;
}

void Habitacion::listarInfo(){
    cout << "Número de Habitación: " << nroHabitacion <<endl;
    cout << "Número de Camas: " << nroCamas <<endl;
    cout << "Capacidad: " << capacidad <<endl;
    cout << "Precio Base: $" << precioBase <<endl;
}

void Habitacion::agregarHuesped(string nombre, string dni, int nroReserva) {
    ReservaHabitacion* reserva = buscarReserva(nroReserva);
    reserva->agregarHuesped(nombre, dni);
    cout << "Acompañante agregado con exito." <<endl;  //solo para hacer el control, despues sacar
}

float Habitacion::calcularCostoRestante(int nroReserva){
	float costo = 0;
	costo = (calcularCostoTotalReserva(nroReserva) - getSenia(nroReserva)) + Reservas[nroReserva]->calcularConsumo();
	return costo;
}

/*ReservaHabitacion* Habitacion::buscarReserva(int nroReserva) {
    for (ReservaHabitacion*& reserva : Reservas) {
        if (reserva->getCodigo() == nroReserva) {
            return reserva;
        }
    }
    // Si no se encuentra la reserva, devolver un puntero nulo.
    return nullptr;
}*/

ReservaHabitacion *Habitacion::buscarReserva(int nroReserva){
	for (size_t i = 0; i < Reservas.size(); ++i) {
		if (Reservas[i]->getCodigo() == nroReserva) {
			return Reservas[i];
		}
	}
	return nullptr;
}

/*void Habitacion::agregarHuesped(string nombre, string apellido, string dni, string nacionalidad, string provincia, string mail, string domicilio, string patente, string telefono, int nroReserva) {
    ReservaHabitacion* reserva = buscarReserva(nroReserva);

    if (reserva) {
        reserva->agregarHuesped(nombre, apellido, dni, nacionalidad, provincia, mail, domicilio, patente, telefono);
    } else {
        // Manejar el caso cuando la reserva no se encuentra
        // Puedes imprimir un mensaje, lanzar una excepción, etc.
        std::cout << "La reserva no fue encontrada." << std::endl;
    }
}creo que no va porque ya agregamos el titular en crearReserva*/




/* bool Habitacion::estaDisponible(Fecha fechaInicio, Fecha fechaFin) {
    for (ReservaHabitacion*& reserva : Reservas) {
        if (fechaFin <= reserva->getFechaEntrada() || fechaInicio >= reserva->getFechaSalida()) { //sonsultar mas tarde
            return false;
        }
    }
    return true;
} */


/*bool Habitacion::estaDisponible(Fecha* fechaInicio, Fecha* fechaFin) {
    for (ReservaHabitacion*& reserva : Reservas) {
        if (!(fechaFin <= reserva->getFechaEntrada() || fechaInicio >= reserva->getFechaSalida())) {
            return false;
        }
    }
    return true;
}*/

Habitacion::~Habitacion() {
	for (size_t i = 0; i < Reservas.size(); ++i) {
			delete Reservas[i];
		}
}
