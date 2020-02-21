#pragma once
#ifndef POLINOMIO_H
#define POLINOMIO_H
#include <string>
#include<iostream>
using namespace std;
class Polinomio {
	friend Polinomio& operator+(const Polinomio&, const Polinomio&);
	friend Polinomio& operator-(const Polinomio&, const Polinomio&);
	friend Polinomio& operator*(const Polinomio&, const Polinomio&);
	friend std::ostream& operator<<(std::ostream&, const Polinomio&);
private :
	int coeficiente[30];
	int exponente[30];
public:
	int cantidad=0;
	Polinomio();
	~Polinomio();
	void ordenar();

	void ingresar();


};
#endif
