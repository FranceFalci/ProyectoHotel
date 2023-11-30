/*
 * ReservaAmenities.h
 *
 *  Created on: 29 nov. 2023
 *      Author: HP
 */

#ifndef RESERVAAMENITIES_H_
#define RESERVAAMENITIES_H_
#include <iostream>
#include "Fecha.h"
using namespace std;

class ReservaAmenities {
private:
	string nombreAmenities;
	Fecha *fecha;
	string hora;
	string dni;
	int nroHabitacion;
public:
	ReservaAmenities(Fecha *fecha, string hora, string dni, int nroHabitacion);
	Fecha *getFecha();
	string getNombre();
	string getHora();
	virtual ~ReservaAmenities();
};

#endif /* RESERVAAMENITIES_H_ */
