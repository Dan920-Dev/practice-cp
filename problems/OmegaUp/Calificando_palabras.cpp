#include <iostream>
#include <string>

using namespace std;

int calcularPuntaje(const string& palabra) {
    int puntaje = 0;
    
    for (char c : palabra) {
        if (isdigit(c)) {
            puntaje += (c - '0');
        } else if (islower(c)) {
            puntaje += (c - 'a' + 10); 
        } else if (isupper(c)) {
            puntaje += 2 * (c - 'A' + 10);
        }
    }
    
    return puntaje;
}

int main() {
    string palabraAna, palabraCarolina;
    cin >> palabraAna >> palabraCarolina;
    
    int puntajeAna = calcularPuntaje(palabraAna);
    int puntajeCarolina = calcularPuntaje(palabraCarolina);
    
    if (puntajeAna > puntajeCarolina) {
        cout << "Ana " << puntajeAna << endl;
    } else {
        cout << "Carolina " << puntajeCarolina << endl;
    }
    
    return 0;
}