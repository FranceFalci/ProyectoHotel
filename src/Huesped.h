/*
 * Huesped.h
 *
 *  Created on: 29 nov. 2023
 *      Author: franc
 */

#ifndef HUESPED_H_
#define HUESPED_H_
#include <iostream>
using namespace std;

class Huesped {
private:
	string nombre;
	string apellido;
	int nroHabitacion;
	string dni;
	string nacionalidad;
	string provincia;
	string mail ;
	string domicilio;
	string patente;
	string telefono;
public:
	void ListarInfo();
	string getDNI();
	string getNombre();
	Huesped(string nombre, string dni);
	Huesped(string nombre,string apellido,int nroHabitacion,string dni,string nacionalidad,string provincia,string mail,string domicilio,string patente,string telefono);

	virtual ~Huesped();
};

#endif /* HUESPED_H_ */
