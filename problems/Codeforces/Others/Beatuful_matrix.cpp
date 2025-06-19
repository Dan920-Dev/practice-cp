// link: https://codeforces.com/contest/263/problem/A

#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    ios::sync_with_stdio(0);
	cin.tie(0);
	
    int a, x = 1, y = 1, iPos = 0, jPos = 0, n = 5, res = 0;
    
    while(n--){
        
       for(int i = 0; i < 5; ++i){
           cin >> a;
           if( a == 1){ iPos = x; jPos = y; }
           y++;
       }
       
      y = 1;
      x++;
    }
 
   
   while(iPos != 3 or jPos != 3){
       
       if(iPos < 3 or iPos > 3){
        res += abs(3 - iPos);
        iPos = 3;
       }
       
       if(jPos < 3 or jPos > 3){
        res += abs(3 - jPos);
        jPos = 3;
       }
       
   }
 
   cout  << res << "\n";
    return 0;
}