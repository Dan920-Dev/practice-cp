#include <bits/stdc++.h>

using namespace std;

int main()
{
    string n = "";
    int sum = 0;
    
    cin >> n;
    
    if(stoi(n) < 0){
        cout << 0 << "\n";
    }else{
        for(int i = 0; i < n.size(); i++){
        int digit = n[i] - '0';
        sum += digit; 
        } 
    
    cout << sum << "\n";
    }
    
    
    return 0;
}