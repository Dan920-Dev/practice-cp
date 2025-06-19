// https://codeforces.com/gym/105505/problem/A

#include <bits/stdc++.h>

using namespace std;

int main(){

    string s;

    cin >> s;

    sort(s.begin(), s.end());

    string ns = "";
    set<char> word;

    for (int i = 0; i < s.size(); i++)
    {
        word.insert(s[i]);
    }
    
    cout << s.size() - word.size() << "\n";
    

    return 0;
}