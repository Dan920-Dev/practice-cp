// link a enunciado: https://omegaup.com/arena/problem/cubote#problems
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long result = 0, n;
    int a, b, c, d, e, f, valorMenor = 51, valorMayor = 0, suma3Caras = 151, suma2Caras = 101;

    cin >> n >> a >> b >> c >> d >> e >> f;

    valorMenor = min(valorMenor, a);
    valorMenor = min(valorMenor, b);
    valorMenor = min(valorMenor, c);
    valorMenor = min(valorMenor, d);
    valorMenor = min(valorMenor, e);
    valorMenor = min(valorMenor, f);

    valorMayor = max(valorMayor, a);
    valorMayor = max(valorMayor, b);
    valorMayor = max(valorMayor, c);
    valorMayor = max(valorMayor, d);
    valorMayor = max(valorMayor, e);
    valorMayor = max(valorMayor, f);

    suma2Caras = min(suma2Caras, a + b);
    suma2Caras = min(suma2Caras, a + c);
    suma2Caras = min(suma2Caras, a + d);
    suma2Caras = min(suma2Caras, a + e);
    suma2Caras = min(suma2Caras, b + c);
    suma2Caras = min(suma2Caras, b + d);
    suma2Caras = min(suma2Caras, b + f);
    suma2Caras = min(suma2Caras, c + b);
    suma2Caras = min(suma2Caras, c + e);
    suma2Caras = min(suma2Caras, c + f);
    suma2Caras = min(suma2Caras, d + f);
    suma2Caras = min(suma2Caras, e + f);

    suma3Caras = min(suma3Caras, e + d + a);
    suma3Caras = min(suma3Caras, a + b + d);
    suma3Caras = min(suma3Caras, e + a + c);
    suma3Caras = min(suma3Caras, a + c + b);
    suma3Caras = min(suma3Caras, b + d + f);
    suma3Caras = min(suma3Caras, c + b + f);
    suma3Caras = min(suma3Caras, e + c + f);
    suma3Caras = min(suma3Caras, e + d + f);

    if (n == 1)
    {
        result = (a + b + c + d + e + f) - valorMayor;
    }
    else
    {
        result = valorMenor * (4 * (n - 1) * (n - 2) + (n - 2) * (n - 2)) + (4 * (n - 1) + 4 * (n - 2)) * suma2Caras + 4 * suma3Caras;
    }

    cout << result;

    return 0;
}
