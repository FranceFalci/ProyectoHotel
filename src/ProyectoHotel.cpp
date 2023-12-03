//============================================================================
// Name        : ProyectoHotel.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "Fecha.h"
#include "Hotel.h"
#include "Consumo.h"


int main() {

	Fecha fecha(5, 10, 2023);
	Fecha fecha2(10, 10, 2023);

	Consumo consumo1("Gaseosa", 678.5);
	Consumo consumo2("Papas", 1100);
	Consumo consumo3("Cafe con leche", 420);

	Hotel hotelAyres;
	hotelAyres.agregarHabitacion(3, 4, 15000);
	hotelAyres.agregarHabitacion(2, 2, 10000);
	hotelAyres.agregarHabitacion(4, 5, 18000);

	int habitacionDisponible = hotelAyres.obtenerHabitacionDisponible(&fecha, &fecha2, 5);
	cout<<"Habitacion disponible: "<< habitacionDisponible<<endl;

	hotelAyres.crearReserva(&fecha, &fecha2, 5, "Carlos", "Perez", "16878878", "Argentino","Tucuman", "asdf@gmail.com", "25 de Mayo 1000", "OER123", "3814567890");
	hotelAyres.buscarReserva(1)->listarInfo();



	return 0;
}


