#ifndef CONSUMO_H_
#define CONSUMO_H_
#include <string>

class Consumo {
    static int autonumerico;
    int codigo;
    std::string nombre;
    float precio;
public:
	Consumo(std::string nombre, float precio);
	virtual ~Consumo();
    void listarInfo();
    float getPrecio();
};

#endif /* HUESPED_H_ */