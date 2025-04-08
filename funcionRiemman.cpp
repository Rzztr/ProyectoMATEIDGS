#include <iostream>
#include <cmath>
#include <functional>

using namespace std;
using Func = function<double(double)>;

// Suma de Riemann
double suma_riemann(Func f, double a, double b, int N) {

    double suma = 0.0;

    double dx = (b - a) / N; // Ancho de subintervalos

    for (int i = 0; i < N; i++) { //funcion suma riemman
        double x = a + i * dx;
        suma += f(x) * dx;
    }
    return suma;
}

int main() {
    int opcion;

    do {
        cout << R"(
                                          _         _____   _                                        
                                         | |       |  __ \ (_)                                       
  ___  _   _  _ __ ___    __ _  ___    __| |  ___  | |__) | _   ___  _ __ ___    __ _  _ __   _ __   
 / __|| | | || '_ ` _ \  / _` |/ __|  / _` | / _ \ |  _  / | | / _ \| '_ ` _ \  / _` || '_ \ | '_ \  
 \__ \| |_| || | | | | || (_| |\__ \ | (_| ||  __/ | | \ \ | ||  __/| | | | | || (_| || | | || | | | 
 |___/ \__,_||_| |_| |_| \__,_||___/  \__,_| \___| |_|  \_\|_| \___||_| |_| |_| \__,_||_| |_||_| |_| 

 Hecho por: T.S.U. Ricardo Reyes L. 
)"<<std::endl;
        cout << "\nFunciones disponibles:\n";
        cout << "{1}: sin(x)  {2}: cos(x)  {3}: x^2  {4}: e^x  [99 para salir]\n";
        cout << "Elije una función (1,2,3,4)...\n";
        cin >> opcion;

        if (opcion == 99) break; // Opción de salida

        Func f;
        switch (opcion) {
            case 1: f = [](double x) { return sin(x); }; break;
            case 2: f = [](double x) { return cos(x); }; break;
            case 3: f = [](double x) { return x * x; }; break;
            case 4: f = [](double x) { return exp(x); }; break;
            default:
                cout << "Opción inválida...\n";
                continue;
        }

        // Pedida al usuario
        double a, b;
        int N;
        cout << "";
        cout << "Límite inferior [a]: ";
        cin >> a;
        cout << "";
        cout << "Límite superior [b]: ";
        cin >> b;
        cout << "";
        cout << "Número de intervalos {Introduzca un numero entero}: ";
        cin >> N;
        cout << "";

        // Cálculo de la integral
        double resultado = suma_riemann(f, a, b, N);
        cout << "Área debajo de la curva: " << resultado << endl;

    } while (true); // Se repite hasta que el usuario ingrese 99 o lo cierre alv

//se le puede poner para funciones con division, pero alch esta muy tardado y ya medio sueño
    cout << "Programa finalizado...\n";
    cout << "Arriba los tacos de asada";
    return 0;
}
