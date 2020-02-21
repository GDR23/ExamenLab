#include "Polinomio.h"
Polinomio::Polinomio() {
 for(int x=0;x<30;x++){
     exponente[x] = 0;
     coeficiente[x] = 0;
 }
}

Polinomio::~Polinomio() {

}
void Polinomio::ingresar() {
    cout << "LONGITUD POLINOMIO=";
    cin >> cantidad;
    for (int x = 0; x < cantidad; x++) {
        cout << "INGRESE EXPONENTE="<<endl;
        cin >> exponente[x];

        cout << "INGRESE COEFICIENTE=" << endl;
        cin >> coeficiente[x];
    }

    ordenar();
}

void Polinomio::ordenar() {
    int copia1 = 0;
    int copia2 = 0;
    int siguiente = 0;
    int siguiente2 = 0;
    for (int x = 0; x < 30; x++) {

        for (int y = 0; y < 29; y++) {
            copia1 = exponente[y];
            siguiente = exponente[y + 1];
            copia2 = coeficiente[y];
            siguiente2 = coeficiente[y + 1];
            if ( copia1< siguiente) {
                
                exponente[y] =siguiente;
                exponente[y + 1] = copia1;
                coeficiente[y] = siguiente2;
                coeficiente[y + 1] = copia2;
            }
        }
    }

}

std::ostream& operator<<(std::ostream& out, const Polinomio& a) {
    string exp = "";
    string coef = "";
    string cadena = "";

    for (int x = 0; x < a.cantidad; x++) {
        coef = to_string(a.coeficiente[x]);
        exp = to_string(a.exponente[x]);
       
        if (x == 0) {
            cadena += coef + "x^" + exp;
        }
        else if (a.exponente[x]==0) {
            if (a.coeficiente[x] >= 0) {
                cadena+= "+" + coef;
            }
            else {
                cadena=  cadena+ coef;
            }

        }
        else if (a.exponente[x] == 1) {
            if (a.coeficiente[x] >= 0) {
                cadena += "+" + coef +"x";
            }
            else {
                cadena += coef + "x";
            }

        }
        else {

            if (a.coeficiente[x] >= 0) {
                cadena += "+" + coef +"x^"+exp;
            }
            else {
                cadena +=  coef + "x^" +exp;
            }

        }
        
    }
    out << cadena<<endl;
    return out;
}

Polinomio& operator+(const Polinomio& a, const Polinomio& b) {
    int num[30];
    int numb[30];
    int expo[30];
    int coefi[30];
    int pos[30];
    int max = 0;
    Polinomio suma;
    for (int x = 0; x < 30; x++) {
        num[x] = 0;
    }
    for (int x = 0; x < a.cantidad; x++) {
        num[x] = a.exponente[x];

    }
    for (int x = 0; x < b.cantidad; x++) {
        numb[x] = b.exponente[x];

    }
    int cont = 0;
    int cont2 = 0;
    for (int x = 0; x < a.cantidad; x++) {
        for (int y = 0; y < b.cantidad; y++) {
            if (num[x] == b.exponente[y]) {
                cont++;
                suma.coeficiente[x] = a.coeficiente[x] + b.coeficiente[y];
                suma.exponente[x] = a.exponente[x];

            }


        }
        if (cont == 0) {
   
            suma.coeficiente[x] = a.coeficiente[x];
            suma.exponente[x] = a.exponente[x];
        }
        cont=0;
    }
    int cont3 = 0;
    for (int x = 0; x < 30; x++) {
        if (suma.coeficiente[x] != 0) {
            cont3++;
        }
       }
        for (int x = 0; x < b.cantidad; x++) {
            for (int y = 0; y < a.cantidad; y++) {

                if (numb[x] == a.exponente[y]) {
                    cont++;

                }


            }
            if (cont == 0) {

                suma.coeficiente[cont3] = b.coeficiente[x];
                suma.exponente[cont3] = b.exponente[x];
                cont3++;
            }
            cont = 0;

    }
        suma.cantidad = cont3;
    suma.ordenar();
    return suma;



}
Polinomio& operator-(const Polinomio& a, const Polinomio& b) {
    int num[30];
    int numb[30];
    int expo[30];
    int coefi[30];
    int pos[30];
    int max = 0;
    Polinomio resta;
    for (int x = 0; x < 30; x++) {
        num[x] = 0;
        numb[x] = 0;
    }
    for (int x = 0; x < a.cantidad; x++) {
        num[x] = a.exponente[x];

    }
    for (int x = 0; x < b.cantidad; x++) {
        numb[x] = b.exponente[x];

    }
    int cont = 0;
    int cont2 = 0;
    for (int x = 0; x < a.cantidad; x++) {
        for (int y = 0; y < b.cantidad; y++) {
            if (num[x] == b.exponente[y]) {
                cont++;
                resta.coeficiente[x] = a.coeficiente[x] - b.coeficiente[y];
                resta.exponente[x] = a.exponente[x];

            }


        }
        if (cont == 0) {

            resta.coeficiente[x] = a.coeficiente[x];
            resta.exponente[x] = a.exponente[x];
        }
        cont = 0;
    }
    int cont3 = 0;
    for (int x = 0; x < 30; x++) {
        if (resta.coeficiente[x] != 0) {
            cont3++;
        }
    }
    for (int x = 0; x < b.cantidad; x++) {
        for (int y = 0; y < a.cantidad; y++) {

            if (numb[x] == a.exponente[y]) {
                cont++;

            }


        }
        if (cont == 0) {

            resta.coeficiente[cont3] = b.coeficiente[x];
            resta.exponente[cont3] = b.exponente[x];
            cont3++;
        }
        cont = 0;

    }
    resta.cantidad = cont3;
    resta.ordenar();
    return resta;



}

Polinomio& operator*(const Polinomio& a , const Polinomio& b) {
    int multi1[30];
    int multi2[30];
    int iguales[30];
    int conta2=0;
    Polinomio multi;
    int cont = 0;
    for (int x = 0; x < 30; x++) {
        multi1[x]=0;
        multi2[x]=0;
       iguales[x]=-1;
    }
    for (int x = 0; x < a.cantidad; x++) {
        for (int y = 0; y < b.cantidad; y++) {
            multi1[cont] = a.coeficiente[x] * b.coeficiente[y];
            multi2[cont] = a.exponente[x] + b.exponente[y];
            cont++;
        }
    }

    for (int x = 0; x < 30; x++) {
        for(int y=0; y<30; y++)
            if (multi2[x] == multi2[y]) {
                if (y == x) {

                }
                else {
                    multi.coeficiente[conta2] = multi1[x] + multi1[y];
                    multi.exponente[conta2] = multi2[x];
                    multi1[x] = 0;
                    multi1[y] = 0;
                    conta2++;
                }
            }
        multi.cantidad = cont;

    }
    multi.ordenar();
    return multi;

}

