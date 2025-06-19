// link: https://codeforces.com/gym/104555/problem/F

#include <bits/stdc++.h>
 
using namespace std;
 
int main (){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    
    int d, c, r, temp, resp = 0, ic = 0, ir = 0;
    cin >> d >> c >> r;
 
    vector<int> cs;
    vector<int> rs;
 
    for (int i = 0; i < c; i++) {
        cin >> temp;
        cs.push_back(temp);
    }
 
    for (int i = 0; i < r; i++) {
        cin >> temp;
        rs.push_back(temp);
    }
 
    while (true) {
        if (cs.size() > ic && d >= cs.at(ic)) {
            d -= cs.at(ic);
            ic++;
            resp++;
        } else if (rs.size() > ir) {
            d += rs.at(ir);
            ir++;
            resp++;
        } else {
            break;
        }
    } 
 
    cout << resp << '\n';
    
    return 0;
}

