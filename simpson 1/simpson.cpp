#include <iostream>
#include <cmath>

using namespace std;

// Función a integrar
double f(double x) {
    return sin(x);
}

// Método de Simpson 1/3 para integración numérica
double simpson13(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = f(a) + f(b);
    
    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        sum += i % 2 == 0 ? 2 * f(x) : 4 * f(x);
    }
    
    return sum * h / 3;
}

int main() {
    double a = 0.0; // Límite inferior de integración
    double b = 3.14159; // Límite superior de integración (pi)
    int n = 1000; // Número de intervalos
    
    double integral = simpson13(a, b, n);
    
    cout << "El valor aproximado de la integral es: " << integral << endl;
    
    return 0;
}