// link: https://codeforces.com/contest/231/problem/A

#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    ios::sync_with_stdio(0);
	cin.tie(0);
	
    int n, x, y, z, res = 0;
    
    cin >> n;
    
    while(n--){
        cin >> x >> y >> z;
        if((x+y+z) == 2 or (x+y+z) == 3){
            res++;
        }
       
    }
    cout << res << "\n";
    
 
    return 0;
}