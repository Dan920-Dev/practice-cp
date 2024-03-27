// link: https://codeforces.com/contest/110/problem/A

#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    
    ios::sync_with_stdio(0);
	cin.tie(0);
	
    long long n;
    
    cin >> n;
    
    string s = to_string(n);
    int cont = 0;
     
     
    for(int i = 0; i < s.size(); ++i){
         if( s[i] == '4' or s[i] == '7'){
            cont++;
         } 
    }
    
    
    if(cont == 4 or cont == 7) cout << "YES";
    else cout << "NO";
    
    return 0;
}

