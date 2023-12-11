/*
 * Hotel.h
 *
 *  Created on: 29 nov. 2023
 *      Author: HP
 */

#ifndef HOTEL_H_
#define HOTEL_H_
#include <vector>
#include <iostream>
using namespace std;
#include "ReservaAmenities.h"
#include "Fecha.h"
#include "Huesped.h"
#include "ReservaHabitacion.h"
#include "Habitacion.h"

class Hotel {
private:
	vector<ReservaAmenities*> reservasAmenities;
	vector<Habitacion*> habitaciones;
	bool verDisponibilidadAmenities(Fecha &fecha, string hora, string nombre);
	int obtenerHabitacionDisponible(Fecha &fechaInicio, Fecha &fechaFin, int capacidad);
	ReservaHabitacion *buscarReserva(int nroReserva);
public:
	Hotel();
	void crearReserva(Fecha &fechaEntrada, Fecha &fechaSalida, int capacidad, string nombre, string apellido, string DNI, string nacionalidad, string provincia, string email, string domicilio, string patenteVehiculo, string telefono);
	void checkIn(int nroReserva, vector<Huesped*> huespedes);
	void checkOut(int nroReserva);
	void agregarReservaAmenities(string nombre, Fecha &fecha, string hora, string dni, int nroHabitacion);
	void agregarHabitacion(int nroCamas, int capacidad, float precioBase);
	int obtenerHoraDelSistema();
	virtual ~Hotel();
};

#endif /* HOTEL_H_ */
