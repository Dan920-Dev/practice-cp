// link: https://codeforces.com/contest/41/problem/A

#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    ios::sync_with_stdio(0);
	cin.tie(0);
 
    string s, t;
    
    cin >> s >> t;
   reverse(s.begin(), s.end());
    if(t == s){
       cout << "YES"; 
    }else{
        cout << "NO";
    }
    return 0;
}