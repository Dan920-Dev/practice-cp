#include <bits/stdc++.h>

using namespace std;

// Función para calcular el número de cuadrados en un tablero n x n
long long calcularCuadrados(int n) {
    return (n * (n + 1) * (2 * n + 1)) / 6;
}

// Función para calcular el número de rectángulos en un tablero n x n
long long calcularRectangulos(int n) {
    return (n * (n + 1) * n * (n + 1)) / 4;
}

int main() {
    int n;
    while (cin >> n) {
        long long cuadrados = calcularCuadrados(n);
        long long rectangulos = calcularRectangulos(n);
        cout << cuadrados << " " << rectangulos << "\n";
    }
    return 0;
}