// link: https://codeforces.com/contest/677/problem/A
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, h, hp, res = 0;

    cin >> n >> h;

    while (n--)
    {
        cin >> hp;

        if (hp > h)
        {
            res += 2;
        }
        else
        {
            res += 1;
        }
    }

    cout << res;
    return 0;
}