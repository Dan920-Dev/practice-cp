#include <bits/stdc++.h>

using namespace std;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // code

    long long n, p, mi, q, shops;
    vector<long long> prices;
    vector<long long> coinsToSpent;

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> p;
        prices.push_back(p);
    }

    cin >> q;

    for (int i = 0; i < q; ++i)
    {
        cin >> mi;
        coinsToSpent.push_back(mi);
    }

    // Para poder aplicar busqueda binaria el vector debe estar ordenado
    sort(prices.begin(), prices.end());

    for (int i = 0; i < q; ++i)
    {
        // Por busqueda binaria
        // Encuentra el primer valor que es mayor al que le envio luego al restar con .begin() estoy obteniendo el numero de datos menores al que envie
        shops = upper_bound(prices.begin(), prices.end(), coinsToSpent[i]) - prices.begin();
        cout << shops << "\n";
    }

    return 0;
}