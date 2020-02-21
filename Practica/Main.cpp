#include"Polinomio.h"
#include<conio.h>
int main() {
	Polinomio x;
	Polinomio y;
	Polinomio add;
	Polinomio resta;
	Polinomio multi;
	x.ingresar();
	y.ingresar();

	cout << x;
	add = x + y;
	resta = x - y;
	multi = x * y;

	cout << add;
	cout << resta;
	cout << multi;
	_getch();
}