// Pole Position

// https://onlinejudge.org/external/121/12150.pdf

#include <bits/stdc++.h>

using namespace std;

int main()

{

    int N, P, C;

    string result = "";

    cin >> N;

    while (N != 0)

    {

        vector<int> v(N, 0);

        result = "";

        for (int i = 0; i < N; ++i)
        {

            cin >> C >> P;

            if (abs(P) > N)
            {

                continue;
            }
            else if (P == 0)
            {

                v[i] = C;
            }
            else
            {

                if ((i + P) >= 0 && (i + P) <= N)
                {

                    v[i + P] = C;
                }
            }
        }

        for (int i = 0; i < N; ++i)
        {

            if (v[i] == 0)
            {

                result = "-1\n";

                break;
            }

            if (i == (N - 1))
            {

                result += to_string(v[i]) + "\n";
            }
            else
            {

                result += to_string(v[i]) + " ";
            }
        }

        cout << result;

        cin >> N;
    }

    return 0;
}