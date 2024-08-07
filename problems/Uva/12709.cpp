// Falling Ants

// https://onlinejudge.org/external/127/12709.pdf

#include <bits/stdc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); 
    cout.tie(nullptr);
    
    // code

    int t, l, w, h;

    cin >> t;

    while (t != 0)
    {
        for(int i = 0; i < 3; ++i){
            cin >> l, w, h;
            int m = l*w*h;
            int f = 9.8 - (9.8/2*h);
        }

        cin >> t;
    }
    
    
    return 0;
}
