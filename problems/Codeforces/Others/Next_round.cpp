// link: https://codeforces.com/contest/158/problem/A

#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    ios::sync_with_stdio(0);
	cin.tie(0);
	
    int n, k, kScore, AC = 0;
    
    cin >> n >> k;
    
    int ai[n];
    
    for(int i = 0 ; i < n; ++i){
        cin >> ai[i]; 
    }
    
    kScore = ai[k - 1];
    
    for(int i = 0; i < n; ++i){
        if(ai[i] >= kScore && ai[i] > 0) AC++;
    }
    cout << AC << "\n";
    
 
    return 0;
}
