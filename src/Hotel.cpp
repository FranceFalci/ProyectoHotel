/*
 * Hotel.cpp
 *
 *  Created on: 29 nov. 2023
 *      Author: HP
 */

#include "Hotel.h"
#include <chrono>
#include <ctime>

Hotel::Hotel() {
	// TODO Auto-generated constructor stub
}

int Hotel::obtenerHabitacionDisponible(Fecha *fechaInicio, Fecha *fechaFin, int capacidad){
	for (size_t i = 0; i < habitaciones.size() ; i++) {
		if (habitaciones[i]->estaDisponible(fechaInicio, fechaFin) && habitaciones[i]->getCapacidad() >= capacidad) {
			return habitaciones[i]->getCodigo();
		}
	}
	return -1;
}

void Hotel::crearReserva(Fecha *fechaEntrada, Fecha *fechaSalida, int capacidad, string nombre, string apellido, string DNI, string nacionalidad, string provincia, string email, string domicilio, string patenteVehiculo, string telefono){
	int nroHabitacion = obtenerHabitacionDisponible(fechaEntrada, fechaSalida, capacidad);
	if (nroHabitacion != -1) {
		habitaciones[nroHabitacion]->crearReserva(fechaEntrada, fechaSalida, nombre, apellido, DNI, nacionalidad, provincia, email, domicilio, patenteVehiculo, telefono);
		cout<<"Reserva creada con exito";
	} else {
		cout<<"Error. No hay habitacion disponible";
	}
}

void Hotel::checkIn(int nroHabitacion, vector<Huesped*> huespedes){
	if (obtenerHoraDelSistema() >= 13) {
		for (size_t i = 0; i < huespedes.size(); ++i) {
			habitaciones[nroHabitacion]->agregarHuesped(huespedes[i]->getNombre(), huespedes[i]->getDNI(), nroHabitacion);
			cout<<"Checkin realizado";
		}
	} else {
		cout<<"Horario no habilitado para checkin";
	}
}

void Hotel::checkOut(int nroReserva){
	ReservaHabitacion *reservaEncontrada = buscarReserva(nroReserva);
	Fecha fechaActual;
	fechaActual.setFechaActual();
	if (fechaActual.sonIguales(*reservaEncontrada->getFechaSalida())) {
		if (obtenerHoraDelSistema() < 11) {
			cout<<"Importe a pagar: $"<<habitaciones[reservaEncontrada->getNroHabitacion()]->calcularCostoRestante(nroReserva)<<endl;
		}
		if (obtenerHoraDelSistema() >= 11 && obtenerHoraDelSistema() <= 13) {
			cout<<"Importe a pagar: $"<<habitaciones[reservaEncontrada->getNroHabitacion()]->calcularCostoRestante(nroReserva) + habitaciones[reservaEncontrada->getNroHabitacion()]->calcularCostoPorNoche()/2 <<endl;
		}
		if (obtenerHoraDelSistema() > 13) {
			cout<<"Importe a pagar: $"<<habitaciones[reservaEncontrada->getNroHabitacion()]->calcularCostoRestante(nroReserva) + habitaciones[reservaEncontrada->getNroHabitacion()]->calcularCostoPorNoche()<<endl;
		}
	}
}

void Hotel::agregarReservaAmenities(string nombre, Fecha *fecha, string hora, string dni, int nroHabitacion){
	if (verDisponibilidadAmenities(fecha, hora, nombre)) {
		ReservaAmenities *amenities = new ReservaAmenities(fecha, hora, dni, nroHabitacion);
		reservasAmenities.push_back(amenities);
	} else {
		cout<<"Amenities ocupado";
	}
}

void Hotel::agregarHabitacion(int nroCamas, int capacidad, float precioBase){
	Habitacion *nuevaHabitacion = new Habitacion(nroCamas, capacidad, precioBase);
	habitaciones.push_back(nuevaHabitacion);
}

bool Hotel::verDisponibilidadAmenities(Fecha *fecha, string hora, string nombre){
	for (size_t i = 0; i < reservasAmenities.size() ; ++i) {
		if (reservasAmenities[i]->getFecha() != fecha && reservasAmenities[i]->getNombre() != nombre && reservasAmenities[i]->getHora() != hora) {
			return true;
		}
	}
	return false;
}

ReservaHabitacion *Hotel::buscarReserva(int nroReserva){
	for (size_t i = 0; i < habitaciones.size(); ++i) {
		ReservaHabitacion *reservaBuscada = habitaciones[i]->buscarReserva(nroReserva);
		if (reservaBuscada != nullptr) {
			cout << "Reserva encontrada en la habitacion " << i << endl;
			return reservaBuscada;
		}
	}
	cout << "La reserva no se encontró en ninguna habitacion." << endl;
	return nullptr;
}

int Hotel::obtenerHoraDelSistema(){
	// Obtener el reloj de sistema actual
	auto now = std::chrono::system_clock::now();

	// Convertir a un formato de tiempo en C
	std::time_t now_c = std::chrono::system_clock::to_time_t(now);

	// Estructura para almacenar la hora actual
	std::tm local_time = *std::localtime(&now_c);

	// Obtener solo la hora actual
	int hora_actual = local_time.tm_hour;

	return hora_actual;
}

Hotel::~Hotel() {
	for (size_t i = 0; i < habitaciones.size(); ++i) {
		delete habitaciones[i];
	}

	for (size_t i = 0; i < reservasAmenities.size(); ++i) {
		delete reservasAmenities[i];
	}
}

