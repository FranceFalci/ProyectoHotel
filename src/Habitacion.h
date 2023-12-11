#ifndef HABITACION_H_
#define HABITACION_H_
#include <iostream>
using namespace std;
#include "Fecha.h"
#include "ReservaHabitacion.h"
#include <vector>

class Habitacion {
    static int autonumerico;
    int nroHabitacion;
    int nroCamas;
    int capacidad;
    float precioBase;
    vector<ReservaHabitacion*> Reservas;
public:
	Habitacion(int nroCamas, int capacidad, float precioBase);
    float calcularCostoPorNoche();
    float calcularCostoTotalReserva(int nroReserva);
    int getCodigo();
    int getCapacidad();
    float getSenia(int nroReserva);
    void crearReserva(Fecha &fechaEntrada, Fecha &fechaSalida, string nombre,string apellido,string dni,string nacionalidad,string provincia,string mail,string domicilio,string patente,string telefono);
    bool estaDisponible(Fecha &fechaInicio, Fecha &fechaFin);
    void listarInfo();
    void agregarHuesped(string nombre, string dni, int nroReserva);
    void agregarHuesped(string nombre,string apellido, string dni,string nacionalidad,string provincia,string mail,string domicilio,string patente,string telefono, int nroReserva);
    float calcularCostoRestante(int nroReserva);
    ReservaHabitacion* buscarReserva(int nroReserva);
	virtual ~Habitacion();
};

#endif /* HABITACION_H_ */
