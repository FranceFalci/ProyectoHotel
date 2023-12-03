#include "Consumo.h"
int Consumo::autonumerico = 1;

Consumo::Consumo(string nombre, float precio) {
	this->codigo = autonumerico++;
    this->nombre = nombre;
    this->precio = precio;
}

void Consumo::listarInfo(){
    cout <<"Codigo: "<< codigo << endl;
    cout <<"Nombre: "<< nombre << endl;
    cout <<"Precio: $"<< precio << endl;
    cout<<"\n";
}

float Consumo::getPrecio(){
    return precio;
}

Consumo::~Consumo() {
	// TODO Auto-generated destructor stub
}
