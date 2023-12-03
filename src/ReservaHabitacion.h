/*
 * ReservaHabitacion.h
 *
 *  Created on: 29 nov. 2023
 *      Author: franc
 */

#ifndef RESERVAHABITACION_H_
#define RESERVAHABITACION_H_
#include "Fecha.h"
#include "Huesped.h"
#include "Consumo.h"
#include <vector>

class ReservaHabitacion {
	static int autonumerico;
	Fecha *fechaEntrada;
	Fecha *fechaSalida;
	int codigo;
	int nroHabitacion;
	vector<Consumo*> consumos;
	vector<Huesped*> huespedes;
public:
	ReservaHabitacion(Fecha *fechaEntrada, Fecha *fechaSalida, int nroHabitacion);
	int getCodigo();
	int getNroHabitacion();
	Fecha *getFechaSalida();
	Fecha *getFechaEntrada();
	int cantidadDias();

	void agregarHuesped(string nombre, string dni);
	void agregarHuesped(string nombre,string apellido,string dni,string nacionalidad,string provincia,string mail,string domicilio,string patente,string telefono);
	void agregarConsumo(Consumo *consumo);
	float calcularConsumo();
	void listarInfo();
	virtual ~ReservaHabitacion();
};

#endif /* RESERVAHABITACION_H_ */
