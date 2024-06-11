#include <iostream>
#include <cmath>
#include "exprtk.hpp"

using namespace std;

// Método de Newton-Raphson
double newtonRaphson(const exprtk::expression<double>& funcion, const exprtk::expression<double>& derivadaFuncion, double x0, double epsilon, int iterMax) {
    double x = x0;
    int iter = 0;
    
    while (iter < iterMax) {
        double fx, dfx;
        funcion.value(x, fx);
        derivadaFuncion.value(x, dfx);
        double deltaX = fx / dfx;
        
        x = x - deltaX;
        
        if (abs(deltaX) < epsilon)
            break;
        
        iter++;
    }
    
    return x;
}

int main() {
    // Entrada de la función
    string funcionStr;
    cout << "Ingrese la funcion (ejemplo: x*x*x - 2): ";
    getline(cin, funcionStr);
    
    // Definir los símbolos y los objetos de expresión
    exprtk::symbol_table<double> symbol_table;
    exprtk::expression<double> funcion, derivadaFuncion;
    
    funcion.register_symbol_table(symbol_table);
    derivadaFuncion.register_symbol_table(symbol_table);
    
    // Compilar las expresiones
    exprtk::parser<double> parser;
    parser.compile(funcionStr, funcion);
    parser.compile(funcionStr, derivadaFuncion);
    
    // Otros parámetros
    double x0 = 1.0; // Valor inicial
    double epsilon = 0.0001; // Tolerancia
    int iterMax = 100; // Máximo número de iteraciones
    
    // Encontrar la raíz
    double raiz = newtonRaphson(funcion, derivadaFuncion, x0, epsilon, iterMax);
    
    cout << "Raiz encontrada: " << raiz << endl;
    
    return 0;
}