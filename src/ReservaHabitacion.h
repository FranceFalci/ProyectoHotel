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
#include <vector>
#include "Consumo.h"


class ReservaHabitacion {
	static int autonumerico;
	Fecha fechaEntrada;
	Fecha fechaSalida;
	int codigo;
	int nroHabitacion;
	vector<Consumo*> consumos;
public:
	int CantidadDias();
	int getCodigo();
	int getNroHabitacion();
	void agregarHuesped(string nombre, string dni);
	void agregarHuesped(string nombre,string apellido,int nroHabitacion,string dni,string nacionalidad,string provincia,string mail,string domicilio,string patente,string telefono);
	float calcularConsumo();
	void agregarConsumo(Consumo *consumo);
	ReservaHabitacion(Fecha fechaEntrada,Fecha fechaSalida,int nroHabitacion);
	virtual ~ReservaHabitacion();
};

#endif /* RESERVAHABITACION_H_ */
