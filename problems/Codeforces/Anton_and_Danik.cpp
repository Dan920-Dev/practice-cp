// link: https://codeforces.com/contest/734/problem/A

#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    ios::sync_with_stdio(0);
	cin.tie(0);
	
    int n, contA = 0, contD = 0;
    string s;
    
    cin >> n >> s;
    
    for(int i = 0; i < s.size(); ++i){
        if(s[i] == 'A'){
            contA++;
        }else{
            contD++;
        }
    }
    if(contD == contA) cout << "Friendship";
    else if(contD > contA) cout << "Danik";
        else cout << "Anton";
    
    return 0;
}