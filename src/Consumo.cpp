#include "Consumo.h"
#include <iostream>
int Consumo::autonumerico = 1;

Consumo::Consumo(std::string nombre, float precio) {
	this->codigo=autonumerico++;
    this->nombre=nombre;
    this->precio=precio;
}

Consumo::~Consumo() {
	// TODO Auto-generated destructor stub
}

void Consumo::listarInfo(){
    std::cout <<"codigo: "<< codigo << std::endl; 
    std::cout <<"nombre: "<< nombre << std::endl; 
    std::cout <<"precio: "<< precio << std::endl; 
}

float Consumo::getPrecio(){
    return precio;
}