// Ejercico de calculadora.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

//Funcion de ingresar numeros
void ingreseNumeros(int& numero1, int& numero2) {
    cout << "ingresa dos numeros para continuar" << endl;
    cout << "ingrese aqui el primer numero --> ";
    cin >> numero1;
    cout << "ingrese aqui el segundo numero --> ";
    cin >> numero2;
}

//Funciones para ejercicio de calculadora
//Funcion overloading de suma 
void suma(int numero1, int numero2) {
    cout << "La suma de los dos numeros da: ";
    cout << numero1 + numero2 << endl;
}
void suma(float numero1, float numero2) {
    cout << "La suma de los dos numeros da: ";
    cout << numero1 + numero2 << endl;
}
void suma(float numero1, int numero2) {
    cout << "La suma de los dos numeros da: ";
    cout << numero1 + numero2 << endl;
}
void suma(int numero1, float numero2) {
    cout << "La suma de los dos numeros da: ";
    cout << numero1 + numero2 << endl;
}
void suma(double numero1, double numero2) {
    cout << "La suma de los dos numeros da: ";
    cout << numero1 + numero2 << endl;
}
void suma(int numero1, double numero2) {
    cout << "La suma de los dos numeros da: ";
    cout << numero1 + numero2 << endl;
}

//Funcion de resta int
void resta(int numero1, int numero2) {
    cout << "La resta de los dos numeros da: ";
    cout << numero1 - numero2 << endl;
}
void resta(float numero1, float numero2) {
    cout << "La resta de los dos numeros da: ";
    cout << numero1 - numero2 << endl;
}
void resta(float numero1, int numero2) {
    cout << "La resta de los dos numeros da: ";
    cout << numero1 - numero2 << endl;
}
void resta(int numero1, float numero2) {
    cout << "La resta de los dos numeros da: ";
    cout << numero1 - numero2 << endl;
}
void resta(double numero1, double numero2) {
    cout << "La resta de los dos numeros da: ";
    cout << numero1 - numero2 << endl;
}
void resta(int numero1, double numero2) {
    cout << "La resta de los dos numeros da: ";
    cout << numero1 - numero2 << endl;
}

//Funcion de multiplicacion int
void multiplicacion(int numero1, int numero2) {
    cout << "La multiplicacion de los dos numeros da: ";
    cout << numero1 * numero2 << endl;
}
void multiplicacion(float numero1, float numero2) {
    cout << "La multiplicacion de los dos numeros da: ";
    cout << numero1 * numero2 << endl;
}
void multiplicacion(float numero1, int numero2) {
    cout << "La multiplicacion de los dos numeros da: ";
    cout << numero1 * numero2 << endl;
}
void multiplicacion(int numero1, float numero2) {
    cout << "La multiplicacion de los dos numeros da: ";
    cout << numero1 * numero2 << endl;
}
void multiplicacion(double numero1, double numero2) {
    cout << "La multiplicacion de los dos numeros da: ";
    cout << numero1 * numero2 << endl;
}
void multiplicacion(int numero1, double numero2) {
    cout << "La multiplicacion de los dos numeros da: ";
    cout << numero1 * numero2 << endl;
}

//Funcion de division int
void division(double numero1, double numero2) {
    cout << "La division de los dos numeros da: ";
    cout << numero1 / numero2 << endl;
}
void division(float numero1, float numero2) {
    cout << "La division de los dos numeros da: ";
    cout << numero1 / numero2 << endl;
}
void division(float numero1, int numero2) {
    cout << "La division de los dos numeros da: ";
    cout << numero1 / numero2 << endl;
}
void division(int numero1, float numero2) {
    cout << "La division de los dos numeros da: ";
    cout << numero1 / numero2 << endl;
}
void division(int numero1, double numero2) {
    cout << "La division de los dos numeros da: ";
    cout << numero1 / numero2 << endl;
}
void division(int numero1, int numero2) {
    cout << "La division de los dos numeros da: ";
    cout << numero1 / numero2 << endl;
}


//Funcion overload para ejercicio de calcular area
void calculaArea(int lado) { //area del cuadrado
    cout << "el area calculada del cuadrado es: ";
    cout << lado * lado << endl;
}
void calculaArea(double base, double altura) { //area del triangulo equilatero
    cout << "el area calculada del triangulo equilatero es: ";
    cout << (base * altura) / 2 << endl;
}
void calculaArea(float radio) { //area del circulo
    const double PI = 3.141592653589793;
    cout << "el area calculada del circulo es: ";
    cout << PI * pow(radio, 2) << endl;
}
void calculaArea(int lado, int ancho) { //area del rectangulo
    cout << "el area calculada del rectangulo es: ";
    cout << lado * ancho << endl;
}


int main()
{
    //Variables
    int opcion;
    int numero1, numero2;

    //EJERCICIO DE CALCULADORA
    ingreseNumeros(numero1, numero2);
    //Menu de opciones para las operaciones de calculadora
    cout << "Seleccione de las siguientes opciones" << endl;
    cout << "opcion 1 --> suma\nopcion 2 --> resta\nopcion 3 --> multiplicacion\nopcion 4 --> division" << endl;
    cout << "ingresa tu opcion --> ";
    cin >> opcion;

    //Seccion de operaciones para calculadora
    switch (opcion) {
    case 1:
        //llamar a la funcion suma
        suma(numero1, numero2);
        break;
    case 2:
        //llamar a la funcion resta
        resta(numero1, numero2);
        break;
    case 3:
        //llamar a la funcion multiplicacion
        multiplicacion(numero1, numero2);
        break;
    case 4:
        //llamar a la funcion de division
        division(numero1, numero2);
        break;
    default:
        cout << "opcion no valida";
        break;
    }


    //variables
    int lado, ancho;
    double base, altura;
    float radio;
    //EJERCICIO DE CALCULAR AREA
    //Menu de opciones para las operaciones de calcular area
    cout << "Seleccione de las siguientes opciones para calcular el area de las siguientes figuras" << endl;
    cout << "opcion 1 --> cuadrado\nopcion 2 --> triangulo equilatero\nopcion 3 --> circulo\nopcion 4 --> rectangulo" << endl;
    cout << "ingresa tu opcion --> ";
    cin >> opcion;

    //Seccion de operaciones para calcular area
    switch (opcion) {
    case 1:
        //Pedir lado
        cout << "ingresa el lado del cuadrado: ";
        cin >> lado;
        //llamar a la funcion calculaArea cuadrado
        calculaArea(lado);
        break;
    case 2:
        //pedir base y altura
        cout << "ingresa la base: ";
        cin >> base;
        cout << "ingresa la altura: ";
        cin >> altura;
        //llamar a la funcion calculaArea triangulo
        calculaArea(base, altura);
        break;
    case 3:
        //pedir radio 
        cout << "ingresa el radio: ";
        cin >> radio;
        //llamar a la funcion calculaArea
        calculaArea(radio);
        break;
    case 4:
        //pedir el lado y el ancho
        cout << "ingresa el lado: ";
        cin >> lado;
        cout << "ingresa el ancho: ";
        cin >> ancho;
        //llamar a la funcion calculaArea
        calculaArea(lado, ancho);
        break;
    default:
        cout << "opcion no valida";
        break;
    }

}
