// https://codeforces.com/gym/105873/problem/D

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long k, n, order = 1;

    cin >> k;
    vector<long long> ingredients(k); // ingredientes

    for (int i = 0; i < k; ++i)
    {
        cin >> ingredients[i];
    }

    cin >> n;

    vector<vector<long long>> matrix(n, vector<long long>(k));
    vector<long long> ingDay(k, 0); // ingredientes por dia

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < k; ++j)
        {

            cin >> matrix[i][j];
            ingDay[j] += matrix[i][j];
        }
    }

    // Calculo del minimo de dias en que se termina mas rapido el primer ingrediente

    long long d;
    long long currDay = -1;
    for (long long i = 0; i < k; i++)
    {
        if (ingDay[i] > 0)
        {
            d = ingredients[i] / ingDay[i];
            if (currDay == -1 || d < currDay)
            {
                currDay = d;
            }
        }
    }

    if (currDay == -1)
    {
        currDay = 0;
    }

    // Por alguna razon hacer las operaciones en una sola pasada es mas lento
    /*for (int j = 0; j < k; ++j)
    {
        ingredients[j] -= ((currDay)*ingDay[j]);
    }*/

    for (long long i = 0; i < k; i++)
    {
        ingDay[i] *= currDay;
    }

    for (long long i = 0; i < k; i++)
    {
        ingredients[i] -= ingDay[i];
    }

    // orden
    for (int i = 0; i < n; ++i)
    {
        // ingredientes
        for (int j = 0; j < k; ++j)
        {

            ingredients[j] = ingredients[j] - matrix[i][j];

            if (ingredients[j] < 0)
            {
                order = i + 1;
                cout << currDay + 1 << " " << order << "\n";
                return 0;
            }
        }
    }

    return 0;
}