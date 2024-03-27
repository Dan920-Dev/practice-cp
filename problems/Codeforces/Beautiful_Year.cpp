// link: https://codeforces.com/contest/271/problem/A
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    
    int y;
    cin >> y;
    string year = to_string(y);
    
    while(true){
        y++;
        string year = to_string(y);
        set<char> yearSet = {year[0],year[1],year[2],year[3]};
        if(yearSet.size() == 4){
            cout << year;
            break;
        }
        
    }
 
   
}