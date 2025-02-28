
#include <iostream>
#include <vector>
#include <random>   // Para generar números aleatorios
#include <numeric>  // Para std::accumulate
using namespace std;

// Función para intercambiar dos elementos en el vector
void intercambia(double& a, double& b) {
    double temp = a;
    a = b;
    b = temp;
}

// Función para ordenar el vector usando el algoritmo de burbuja
void ordenacionBurbuja(vector<double>& v) {
    int n = v.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            // Comparación de elementos adyacentes
            if (v[j] < v[j + 1]) {  // Cambiamos el signo para ordenar de mayor a menor
                intercambia(v[j], v[j + 1]);  // Llamada a la función de intercambio
            }
        }
    }
}

int main() {
    // Declarar el vector de tipo double llamado v1
    vector<double> v1;

    // Configurar el generador de números aleatorios
    random_device rd;
    default_random_engine generator(rd());
    uniform_real_distribution<double> distribution(1.55, 1.90);

    // Generar 1000 números aleatorios y almacenarlos en el vector
    for (int i = 0; i < 1000; i++) {
        double num = distribution(generator);
        v1.push_back(num);
    }

    // Calcular e imprimir el promedio antes de ordenar
    double suma = accumulate(v1.begin(), v1.end(), 0.0);
    double promedio = suma / v1.size();
    cout << "El promedio de estatura antes de ordenar es: " << promedio << " metros" << endl;

    // Ordenar el vector de mayor a menor usando el algoritmo de burbuja
    ordenacionBurbuja(v1);

    // Imprimir las estaturas ordenadas
    cout << "Estaturas ordenadas de mayor a menor:" << endl;
    for (double estatura : v1) {
        cout << estatura << " ";
    }
    cout << endl;

    // Calcular e imprimir el promedio después de ordenar (debe ser igual al anterior)
    suma = accumulate(v1.begin(), v1.end(), 0.0);
    promedio = suma / v1.size();
    cout << "El promedio de estatura despues de ordenar es: " << promedio << " metros" << endl;

    return 0;
}



