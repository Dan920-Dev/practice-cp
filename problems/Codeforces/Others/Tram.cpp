// link: https://codeforces.com/contest/116/problem/A

#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    ios::sync_with_stdio(0);
	cin.tie(0);
 
    int n, ai, bi, d = 0, res = 0;
    
    cin >> n;
    
    while(n--){
        cin >> ai >> bi;
        d += bi;
        d = d - ai;
        if(d > bi) bi = d;
        if(bi > res) res = bi;
    }
    
    cout << res ;
    return 0;
}