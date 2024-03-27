// link: https://codeforces.com/contest/96/problem/A
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    
    string s;
    int cont = 1, current = 0, ant = 0;
    cin >> s;
 
    
    for(int i = 0; i < s.size(); ++i){
        
        if(i > 0){
           current = s[i];
           ant = s[i - 1];
           if(current == ant){
               cont++;
           }else{
               cont = 1;
           }
           
           if(cont == 7) break;
        }
        
    }
 
   if(cont == 7){
       cout << "YES\n";
   }else{
       cout << "NO\n";
   }
}