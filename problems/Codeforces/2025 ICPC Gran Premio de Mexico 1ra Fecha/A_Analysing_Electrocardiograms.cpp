// https://codeforces.com/gym/105873/problem/A

#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
	string s = "";
	long n;
 
	cin >> s;
	cin >> n;
 
	for(int i = 0; i < n; ++i) {
	    bool flag = false;
	    string p;
 
		cin >> p;
    	string s2 = s;
    
    	for(int k = 0; k < p.length() / s.length(); ++k) {
            if(s2 == p){
                flag = true;
    				break;
            }
            
            s2 += s;
    	}
 
		if(flag) {
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	}
 
 
	return 0;
}