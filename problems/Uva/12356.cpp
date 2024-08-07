// Army buddies
// https://onlinejudge.org/external/123/12356.pdf

#include <bits/stdc++.h>

using namespace std;

int main(){

    long long s, b, l, r, L_Array[100001], R_Array[100001];

    cin >> s >> b;
    while (s != 0 && b != 0)
    {

        for (int i = 0; i <= s; ++i)
        {
            L_Array[i] = i - 1;
            R_Array[i] = i + 1;
        }
        
        for (int i = 0; i < b; i++)
        {
            cin >> l >> r;
            if (L_Array[l] < 1)
            {
                cout << "* ";
            }else{
                cout << L_Array[l] << " ";
            }

            if(R_Array[r] > s){
                cout << "*\n";
            }else{
                cout << R_Array[r] << "\n";
            }
            L_Array[R_Array[r]] = L_Array[l];
            R_Array[L_Array[l]] = R_Array[r];
        }

        cout << "-\n";
        
        cin >> s >> b;
    }
    
    return 0;
}
