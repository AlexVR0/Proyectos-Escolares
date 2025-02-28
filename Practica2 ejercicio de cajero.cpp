#include <iostream>
#include <vector>
#include<string>
using namespace std;

//Variable global saldo
double saldo = 5000.00;

//Funcion que imprime el saldo
void mostrarSaldo(double saldo) {
    cout << "Tu saldo disponible es de: $" << saldo;
}

//Funcion de retiro de saldo
void retirarSaldo(double& saldo, double retirarCantidad) {
    saldo -= retirarCantidad;
}



int main()
{
    //Variables
    string contrasena = "AB31q";
    string verificarCont;
    int opcion = 0;
    int nip = 4721;
    int verifNip = 0;
    double retirarCantidad = 0;
    double saldoActual = 6000;

    //Comprobar contraseña
    cout << "Ingrese su contrasena: ";
    cin >> verificarCont;
    cout << "Ingrese su nip: ";
    cin >> verifNip;
    if (verificarCont == contrasena && nip == verifNip) {
        cout << "acceso correcto" << endl;
        cout << "opcion: 1 (retiro de efectivo)\nopcion: 2 (consulta de saldo)\n--> ";
        cin >> opcion;
        //Agregar opciones de retiro de efectivo y consulta de saldo
        switch (opcion) {
        case 1:
            //Preguntar por la cantidad a retirar y verificar que no exceda el saldo disponible
            cout << "Que cantidad desea retirar?\n-->";
            cin >> retirarCantidad;
            if (retirarCantidad > saldoActual || retirarCantidad <= 0) {
                cout << "Cantidad invalida, intente de nuevo";
            }
            else { //Simular la entrega de efectivo y peticion de actualizacion
                cout << "Dispensando efectivo..." << endl;
                retirarSaldo(saldoActual, retirarCantidad);
                cout << "Actualizando nuevo saldo disponible" << endl;
                cout << "su saldo ahora es de: $" << saldoActual << endl;
                cout << "Efectivo dispensado, por favor tome su dinero" << endl;
            }
            break;
        case 2:
            //Mostrar saldo con funcion
            mostrarSaldo(saldo);
            break;
        default:
            cout << "opcion no valida";
            break;
        }
    }
    else {
        cout << "acceso denegado";
    }

}
