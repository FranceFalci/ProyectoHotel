/*
 * ReservaAmenities.cpp
 *
 *  Created on: 29 nov. 2023
 *      Author: HP
 */

#include "ReservaAmenities.h"

ReservaAmenities::ReservaAmenities() {
	// TODO Auto-generated constructor stub

}

Fecha *ReservaAmenities::getFecha(){
	return fecha;
}

string ReservaAmenities::getNombre(){
	return nombreAmenities;
}

string ReservaAmenities::getHora(){
	return hora;
}

ReservaAmenities::~ReservaAmenities() {
	// TODO Auto-generated destructor stub
}

