// link: https://codeforces.com/gym/104466/problem/I

#include <bits/stdc++.h>

using namespace std;

struct hr
{
    int n, p;
};

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q, n2, r, pos, cont = 1, min = 0, ultima = 0, numEsp = 1;

    cin >> n;
    vector<hr> p(n);
    set<int> vacios;
    vector<int> saltos;

    // Almacenamiento de ranas en posicion
    for (int i = 0; i < n; ++i)
    {
        hr values;
        cin >> q;
        values.n = i + 1;

        values.p = q;

        p[i] = values;

        while (cont < q)
        {
            vacios.insert(cont);
            cont++;
        }
        cont++;

        if (i == (n - 1))
            ultima = q;
    }

    cin >> n2;

    while (n2--)
    {

        cin >> r;         // rana
        pos = p[r - 1].p; // posicion donde esta la rana

        if (vacios.size() > 0)
        {
            // ********

            auto nextEmpty = vacios.lower_bound(pos);
            // cout << "pos : " << pos << "\n";
            // cout << "Min: " << *nextEmpty;
            if (pos > *nextEmpty)
            {
                saltos.push_back(ultima + 1);
                p[r - 1].p = ultima + 1;
                vacios.insert(pos);
                ultima++;
            }
            else
            {
                saltos.push_back(*nextEmpty);
                p[r - 1].p = *nextEmpty;
                vacios.insert(pos);
                vacios.erase(*nextEmpty);
            }
        }
        else
        {

            saltos.push_back(ultima + 1);
            p[r - 1].p = ultima + 1;
            vacios.insert(pos);
            ultima++;
        }
    }

    for (int i = 0; i < saltos.size(); ++i)
    {
        cout << saltos[i] << "\n";
    }

    return 0;
}
