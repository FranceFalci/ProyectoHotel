#ifndef CONSUMO_H_
#define CONSUMO_H_
#include <iostream>
using namespace std;

class Consumo {
    static int autonumerico;
    int codigo;
    string nombre;
    float precio;
public:
	Consumo(string nombre, float precio);
	void listarInfo();
    float getPrecio();
	virtual ~Consumo();

};

#endif /* CONSUMO_H_ */
