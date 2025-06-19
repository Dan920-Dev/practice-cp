#include <bits/stdc++.h>

using namespace std;

// Definiciones de macros para facilitar la codificación
#define fi first                // Primer elemento de un par
#define se second               // Segundo elemento de un par
#define pb push_back            // Método para añadir elementos a un vector
#define MOD 1000000007          // Módulo común utilizado para operaciones
#define INF 1000000000          // Valor infinito utilizado en comparaciones
#define MAX 1000                // Valor máximo para límites de arreglos
#define ENDL '\n'               // Representación de nueva línea
#define SZ(x) ((int)(x).size()) // Tamaño de un contenedor
#define ALL(x) begin(x), end(x) // Iteradores para todo un contenedor

typedef long long ll;      // Definición de tipo largo
typedef pair<int, int> pi; // Definición de un par de enteros
typedef vector<int> vi;    // Vector de enteros
typedef vector<pi> vii;    // Vector de pares de enteros

int cBit = 0; // Contador de bits comodín ('*')

string n, m; // Variables para almacenar las cadenas de bits recibidas
string M;    // Variable para construir el mensaje recuperado
ll N;        // Variable para almacenar el número entero representado por N

// Función que comprueba si el número binario M es divisible por N
bool check()
{
    ll carry = 0; // Variable para almacenar el residuo de la división

    // Recorre cada bit en M
    for (int i = 0; i < SZ(M); i++)
    {
        carry <<= 1LL; // Desplaza el carry a la izquierda (equivalente a multiplicar por 2)

        // Si el bit actual de M es '1', se suma 1 al carry
        if (M[i] == '1')
        {
            carry |= 1LL; // Establece el bit menos significativo de carry
        }
        // Se toma el residuo de carry dividido por N
        carry %= N;
    }

    // Devuelve true si el residuo es cero, indicando que M es divisible por N
    return carry == 0;
}

// Función para establecer los valores de M y N basados en un "mask"
void setValues(ll mask)
{
    int ln = SZ(n), lm = SZ(m); // Tamaños de n y m

    int ap = 0; // Contador de posiciones de bits comodín
    M = m;      // Inicializa M con m
    N = 0;      // Reinicia N a 0

    // Recorre los bits en m
    for (int i = 0; i < lm; i++)
    {
        if (M[i] == '*') // Si se encuentra un comodín
        {
            M[i] = '0'; // Asigna '0' por defecto
            // Si el bit correspondiente en mask está activo, se asigna '1'
            if (mask & (1 << ap))
            {
                M[i] = '1';
            }
            ap++; // Incrementa el contador de posiciones
        }
    }

    // Recorre los bits en n
    for (int i = 0; i < ln; i++)
    {
        int b = ln - i - 1; // Posición en el número binario
        if (n[i] == '*')    // Si se encuentra un comodín
        {
            // Establece el bit correspondiente en N según mask
            if (mask & (1LL << ap))
            {
                N |= (1LL << b); // Activa el bit b en N
            }
            ap++; // Incrementa el contador de posiciones
        }
        else if (n[i] == '1') // Si el bit es '1'
        {
            N |= (1LL << b); // Activa el bit b en N
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); // Mejora la eficiencia de la entrada/salida
    cin.tie(0);                   // Desactiva la sincronización con C stdio
    cout.tie(0);                  // Desactiva la sincronización de salida

    cin >> m >> n; // Lee las cadenas de bits m y n

    // Contar la cantidad de bits comodín en m y n
    for (char x : m)
    {
        if (x == '*')
        {
            cBit++; // Incrementa el contador de comodines
        }
    }

    for (char x : n)
    {
        if (x == '*')
        {
            cBit++; // Incrementa el contador de comodines
        }
    }

    // Cálculo del límite para la generación de combinaciones posibles
    int lim = (1 << cBit); // 2^cBit
    // Se generan combinaciones basadas en el número de comodines

    // Prueba todas las combinaciones de bits comodín
    for (ll mask = 0; mask < lim; mask++)
    {
        setValues(mask); // Establece los valores de M y N basados en la máscara actual

        // Verifica si el mensaje es válido
        if (check())
        {
            cout << M << ENDL; // Imprime el mensaje M si es divisible por N
            return 0;          // Termina el programa
        }
    }

    cout << "-1\n"; // Imprime -1 si no se encontró ningún mensaje válido

    return 0; // Fin del programa
}

