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

int Hotel::obtenerHabitacionDisponible(Fecha &fechaInicio, Fecha &fechaFin, int capacidad){
	for (size_t i = 0; i < habitaciones.size() ; i++) {
		if (habitaciones[i]->estaDisponible(fechaInicio, fechaFin) && habitaciones[i]->getCapacidad() >= capacidad) {
			return habitaciones[i]->getCodigo();
		}
	}
	return -1;
}

void Hotel::crearReserva(Fecha &fechaEntrada, Fecha &fechaSalida, int capacidad, string nombre, string apellido, string DNI, string nacionalidad, string provincia, string email, string domicilio, string patenteVehiculo, string telefono){
	cout<<" adentro de crear reserva"<<endl;
	int nroHabitacion = obtenerHabitacionDisponible(fechaEntrada, fechaSalida, capacidad);
	cout<<"hab disponible"<<nroHabitacion<<endl;

	if (nroHabitacion != -1) {
		cout<<" adentro del if"<<endl;

		habitaciones[nroHabitacion]->crearReserva(fechaEntrada, fechaSalida, nombre, apellido, DNI, nacionalidad, provincia, email, domicilio, patenteVehiculo, telefono);
		cout<<"Reserva creada con exito";
	} else {
		cout<<"Error. No hay habitacion disponible";
	}
}

void Hotel::checkIn(int nroReserva, vector<Huesped*> huespedes){
	ReservaHabitacion *reservaEncontrada = buscarReserva(nroReserva);
	int nroHabitacion = reservaEncontrada->getNroHabitacion();
	Fecha fechaActual;
	fechaActual.setFechaActual();

	if (fechaActual.sonIguales(reservaEncontrada->getFechaEntrada())) {
		if (obtenerHoraDelSistema() >= 13) {
			for (size_t i = 0; i < huespedes.size(); ++i) {
				habitaciones[nroHabitacion]->agregarHuesped(huespedes[i]->getNombre(), huespedes[i]->getDNI(), nroReserva);
			}
			cout<<"Checkin realizado"<<endl;
		} else {
			cout<<"Horario no habilitado para checkin";
		}
	}else {
		cout<<"ERROR! Fecha no correspondiente al checkin de la reserva"<<endl;
	}
}

void Hotel::checkOut(int nroReserva){
	cout<<"Realizando check out.."<<endl;
	ReservaHabitacion *reservaEncontrada = buscarReserva(nroReserva);
	Fecha fechaActual;
	fechaActual.setFechaActual();
	if (fechaActual.sonIguales(reservaEncontrada->getFechaSalida())) {
//	if(true){
		if (obtenerHoraDelSistema() < 11) {
			cout<<"Importe a pagar: $"<<habitaciones[reservaEncontrada->getNroHabitacion()]->calcularCostoRestante(nroReserva)<<endl;
		}
		if (obtenerHoraDelSistema() >= 11 && obtenerHoraDelSistema() <= 13) {
			cout<<"Importe a pagar: $"<<habitaciones[reservaEncontrada->getNroHabitacion()]->calcularCostoRestante(nroReserva) + habitaciones[reservaEncontrada->getNroHabitacion()]->calcularCostoPorNoche()/2 <<endl;
		}
		if (obtenerHoraDelSistema() > 13) {
			cout<<"Importe a pagar: $"<<habitaciones[reservaEncontrada->getNroHabitacion()]->calcularCostoRestante(nroReserva) + habitaciones[reservaEncontrada->getNroHabitacion()]->calcularCostoPorNoche()<<endl;
		}
	}else{
		cout<<"ERROR! no es fecha de salida para la correspondiente reserva"<<endl;
	}
}

void Hotel::agregarReservaAmenities(string nombre, Fecha &fecha, string hora, string dni, int nroHabitacion){
	if (verDisponibilidadAmenities(fecha, hora, nombre)) {
		ReservaAmenities *amenities = new ReservaAmenities(fecha, hora, dni, nroHabitacion,nombre);
		reservasAmenities.push_back(amenities);
		cout<<"Amenities reservado. Nombre: "<<nombre<<" en la fecha:  "<<fecha<<" y hora: "<<hora<<endl;

	} else {
		cout<<"ERROR! Amenities ocupado"<<endl;;
	}
}

void Hotel::agregarHabitacion(int nroCamas, int capacidad, float precioBase){
	Habitacion *nuevaHabitacion = new Habitacion(nroCamas, capacidad, precioBase);
	habitaciones.push_back(nuevaHabitacion);
}


bool Hotel::verDisponibilidadAmenities(Fecha &fecha, string hora, string nombre) {
    for (size_t i = 0; i < reservasAmenities.size(); ++i) {
        if (fecha.sonIguales(reservasAmenities[i]->getFecha()) &&
            reservasAmenities[i]->getNombre() == nombre &&
            reservasAmenities[i]->getHora() == hora) {
            return false;  // Reservation found that matches the conditions
        }
    }
    return true;  // No matching reservation found
}


ReservaHabitacion *Hotel::buscarReserva(int nroReserva){
	for (size_t i = 0; i < habitaciones.size(); ++i) {
		ReservaHabitacion *reservaBuscada = habitaciones[i]->buscarReserva(nroReserva);
		if (reservaBuscada != nullptr) {
//			cout << "Reserva encontrada en la habitacion " << i << endl;
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

