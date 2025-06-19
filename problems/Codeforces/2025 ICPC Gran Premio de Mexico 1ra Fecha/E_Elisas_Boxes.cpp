// https://codeforces.com/gym/105873/problem/E

#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    long n, m, indexFound = 0;
    vector<long> capacity;
    bool flag = false;
    
    
    cin >> n >> m;
    
    for(int  i = 0; i < n; ++i){
        long ni;
        
        cin >> ni;
        capacity.push_back(ni);
    }
    
    
    for(int  i = 0; i < n; ++i){
        if(capacity[i] >= m){
            indexFound = (long)i;
            flag = true;
            break;
            break;
        }
    }
    
    if(flag){
        cout << indexFound + 1 << endl;
    }else{
        cout << "-1" << endl;
    }
    
 
    
    return 0;
}