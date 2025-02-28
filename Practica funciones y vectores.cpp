// Practica0.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <unordered_map>
#include <limits>
#include <algorithm>
using namespace std;
using namespace chrono;

//funcion prototipo
void imprime(vector<int> v)
{
    for (auto elemento : v)
    {
        cout << elemento << " , ";
    }
    cout << endl;
    system("pause");
    system("cls");
}

void imprimeDouble(vector<double> v)
{
    for (auto elemento : v)
    {
        cout << elemento << " , ";
    }
    cout << endl;
    system("pause");
    system("cls");
}

void multiplicador(long long int numero)
{
    //Variables
    int i;
    do {
        //bucle para multiplicar
        for (int iterador = 0; iterador < 5; iterador++) {
            numero *= 10;
            cout << "Tu numero es: " << numero << endl;
        }
        cout << "detener ingresa 0\ncontinuar ingresa 1\nopcion: ";
        cin >> i;

    } while (i != 0);
}

void numeroMayor(vector<int>& arr)
{
    int mayor = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] > mayor) {
            mayor = arr[i];
        }
    }
    cout << "El valor mas alto es: " << mayor;
}

void tresMayores(vector<int>& vec) {
    int n = vec.size();
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;

        for (int j = 0; j < n - i - 1; j++) {
            if (vec[j] < vec[j + 1]) {
                swap(vec[j], vec[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            cout << "El primer valor mas alto es: " << vec[0] << endl;
            cout << "El segundo valor mas alto es: " << vec[1] << endl;
            cout << "El tercero valor mas alto es: " << vec[2] << endl;
            break;
        }
    }
}

void segundoMayor(vector<double>& vec) {
    int n = vec.size();
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;

        for (int j = 0; j < n - i - 1; j++) {
            if (vec[j] < vec[j + 1]) {
                swap(vec[j], vec[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            cout << "El segundo valor mas alto es: " << vec[1] << endl;
            break;
        }
    }
}

void segundoMenor(vector<double>& vec) {
    int n = vec.size();
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;

        for (int j = 0; j < n - i - 1; j++) {
            if (vec[j] < vec[j + 1]) {
                swap(vec[j], vec[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            cout << "El segundo valor menor es: " << vec[998] << endl;
            break;
        }
    }
}

void mayorFrecuencia(vector<double>& vec) {
    unordered_map<double, int> frecuencia;
    for (double num : vec) {
        frecuencia[num]++;
    }
    double elementoMasRepetido = numeric_limits<double>::min();
    int maxFrecuencia = 0;

    for (const auto& pair : frecuencia) {
        if (pair.second > maxFrecuencia) {
            maxFrecuencia = pair.second;
            elementoMasRepetido = pair.first;
        }
    }
    cout << "El elemento que mas se repite es: " << elementoMasRepetido << endl;
    cout << "Se repite " << maxFrecuencia << " veces" << endl;
}

void numeroFaltante(vector<int>& vec) {
    srand(time(0)); //semilla
    
    for (int i = 0; i < vec.size() - 1; i++) {
        if (vec[i + 1] - vec[i] != 1) {
            cout << "El numero faltante es: " << vec[i] + 1;
            break;
        }
    }
}

void mayorFrecuenciaParImpar(vector<int>& vec) {
    vector<int> par, impar;
    unordered_map<int, int> frecuencia;
    for (int num : vec) {
        frecuencia[num]++;
        if (num % 2 == 0) {
            par.push_back(num);
        }
        else {
            impar.push_back(num);
        }
    }
    
    int elementoMasRepetido = numeric_limits<int>::min();
    int maxFrecuencia = 0;

    for (const auto& pair : frecuencia) {
        if (pair.second > maxFrecuencia) {
            maxFrecuencia = pair.second;
            elementoMasRepetido = pair.first;
        }
    }
    cout << "Estos son los pares: ";
    imprime(par);
    cout << "Estos son los impares: ";
    imprime(impar); 
    cout << "El elemento que mas se repite es: " << elementoMasRepetido << endl;
    cout << "Se repite " << maxFrecuencia << " veces" << endl;
    
}

void invertirArreglo(vector<int>& vec) {
    int n = vec.size();
    for (int i = 0; i < n / 2; i++) {
        swap(vec[i], vec[n - i - 1]);
    }
    cout << endl; 
}

void numeroFaltanteDouble(vector<double>& vec) {
    for (int i = 0; i < vec.size() - 1; i++) {
        if (vec[i + 1] - vec[i] != 1.0) {
            cout << "el numero faltante es: " << vec[i] + 1.0 << endl;
        }
    }
}



int main()
{
    //Arreglo  convencional
    vector<int> arr = { 30, 80, 35, 40, 50 };

    //Vector para numero faltante
    vector<int> v1{ 1, 2, 3, 4, 5, 6, 8, 9 };

    //ARREGLO DE 1000 ELEMENTOS INT (vint)
    vector<int> vint;
    random_device rd;
    default_random_engine gen(rd());
    uniform_int_distribution<int> distribution(1, 1000);
    int num = 1000;
    for (int i = 0; i < num; i++) {
        int num = distribution(gen);
        vint.push_back(num);
    }

    //ARREGLO DE 1000 ELEMENTOS DOUBLE
    vector<double> vdouble;
    random_device rd;
    default_random_engine gen(rd());
    uniform_real_distribution<double> distribution(1, 1000);
    double num = 1000;
    for (int i = 0; i < num; i++) {
        double num = distribution(gen);
        vdouble.push_back(num);
    }

    //Arreglo para invertir valores
    srand(time(0)); //semilla
    vector<int> v;
    for (int i = 1; i <= 10; i++) {
        v.push_back(rand() % 101);
    }
    cout << "tamano vector: " << v.size() << endl;

    //Arreglo para encontrar valores
    srand(time(0)); //semilla
    vector<double> v;
    for (double i = 1; i <= 10; i++) {
        v.push_back(rand() % 101);
    }
    cout << "tamano vector: " << v.size() << endl;




    //LLAMADO A FUNCIONES

    multiplicador(10);

    numeroMayor(arr);

    tresMayores(vint);

    segundoMayor(vdouble);

    segundoMenor(vec);

    mayorFrecuencia(vdouble);

    numeroFaltante(v1);

    mayorFrecuenciaParImpar(vint);

    cout << "Areglo sin invertir: ";
    imprime(v);
    invertirArreglo(v);
    cout << "Arreglo invertido: ";
    imprime(v); 

    numeroFaltanteDouble(v);

}
