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
#include "Huesped.h"

#include "Consumo.h"


int main() {

	Fecha fecha(11, 12, 2023);
	Fecha fecha2(12, 12, 2023);

	Consumo consumo1("Gaseosa", 678.5);
	Consumo consumo2("Papas", 1100);
	Consumo consumo3("Cafe con leche", 420);
	vector<Huesped*> listaHuespedes;

	 listaHuespedes.push_back(new Huesped("Juan Perez", "123456789"));
	 listaHuespedes.push_back(new Huesped("Maria Rodriguez", "987654321"));
	 listaHuespedes.push_back(new Huesped("Carlos Gonzalez", "456789012"));

	Hotel hotelAyres;
	hotelAyres.agregarHabitacion(3, 4, 15000);
	hotelAyres.agregarHabitacion(2, 2, 10000);
	hotelAyres.agregarHabitacion(4, 5, 18000);


	hotelAyres.crearReserva(fecha, fecha2, 5, "Carlos", "Perez", "16878878", "Argentino","Tucuman", "asdf@gmail.com", "25 de Mayo 1000", "OER123", "3814567890");
	hotelAyres.checkIn(0,listaHuespedes);
	hotelAyres.agregarReservaAmenities("pileta", fecha, "11:00", "16878878" , 2);
	hotelAyres.agregarReservaAmenities("pileta", fecha, "11:00", "16878878" , 2);

	hotelAyres.checkOut(0);




	return 0;
}


