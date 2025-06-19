// link: https://codeforces.com/gym/104466/problem/G

#include <bits/stdc++.h>
#include <stdlib.h>

using namespace std;

int numDigits(int cant)
{
    int resp = 0, res = cant;
    while (res > 0)
    {
        res = floor(res / 10);
        resp++;
    }
    return resp;
}

int main()
{

    int n, num;
    cin >> n;

    int dig = numDigits(n);
    num = 10 * (dig - 1);
    if (n < 10)
        num++;

    int max = floor(n / pow(10, dig - 1));
    for (int i = 1; i <= max; i++)
    {
        int numero = 0;
        for (int j = 0; j < dig; j++)
        {
            numero += pow(10, j) * i;
        }
        if (numero <= n)
        {
            num++;
        }
    }

    cout << num << '\n';

    return 0;
}