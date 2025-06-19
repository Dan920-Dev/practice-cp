// link: https://codeforces.com/contest/266/problem/B

#include <iostream>
#include <string>
 
using namespace std;
 
int main() {
    int n, t;
    cin >> n >> t;
    string cola;
    cin >> cola;
 
    for (int segundo = 0; segundo < t; segundo++) {
        for (int i = 0; i < n - 1; i++) {
            if (cola[i] == 'B' && cola[i + 1] == 'G') {
                // Realiza el intercambio
                swap(cola[i], cola[i + 1]);
                i++;  // Avanza dos posiciones para evitar intercambios múltiples en un segundo
            }
        }
    }
    
    cout << cola;
 
    // Encuentra la posición de la última niña en la cola
}