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

class Hotel {
private:
	vector<ReservaAmenities*> reservasAmenities;
public:
	Hotel();
	int obtenerHabitacionDisponible(Fecha *fechaInicio, Fecha *fechaFin, int capacidad);
	void crearReserva(Fecha *fechaEntrada, Fecha *fechaSalida, int capacidad, string nombre, string apellido, string DNI, string nacionalidad, string provincia, string email, string domicilio, string patenteVehiculo, string telefono);
	bool checkIn(int nroHabitacion, vector<Huesped*> huespedes);
	float checkOut(int nroReserva);
	void agregarReservaAmenities(string nombre, Fecha *fecha, string hora, string dni, int nroHabitacion);
	bool verDisponibilidadAmenities(Fecha *fecha, string hora, string nombre);
	ReservaHabitacion buscarReserva(int nroReserva);
	virtual ~Hotel();
};

#endif /* HOTEL_H_ */
