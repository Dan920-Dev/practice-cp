#include <bits/stdc++.h>

using namespace std;

#define Fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

pair<int,string> applyOperationsInOrder(string s, int k){
    char c_ant = s[0]; 
    int count = 0, k2 = 1;

    for (int i = 1; i < s.size(); i++)
    {
        if(c_ant == s[i]){
            k2++;
            if(k2 == k){
                if(s[i] == '1'){
                    s[i] = '0';
                    c_ant = '0';
                }else{
                    s[i] = '1';
                    c_ant = '1';
                }
                k2 = 1;
                count++;
            }else{
                c_ant = s[i];
            }
        }else{
            c_ant = s[i];
            k2 = 1;
        }
    }

    pair<int,string> res;

    res.first = count;
    res.second = s;
    
    return res;
}

pair<int,string> applyOperationsInOrder2(string s, int k){
    char c_ant = s[s.size() - 1]; 
    int count = 0, k2 = 1;

    for (int i = s.size() - 2; i >= 0; i--)
    {
        if(c_ant == s[i]){
            k2++;
            if(k2 == k){
                if(s[i] == '1'){
                    s[i] = '0';
                    c_ant = '0';
                }else{
                    s[i] = '1';
                    c_ant = '1';
                }
                k2 = 1;
                count++;
            }else{
                c_ant = s[i];
            }
        }else{
            c_ant = s[i];
            k2 = 1;
        }
    }

    pair<int,string> res;

    res.first = count;
    res.second = s;
    
    return res;
}

pair<int,string> applyOperationsInReverseOrder(string s, int k){
    pair<int,string> res;
    char c_ant = s[(s.size()/2)]; 
    int count = 0, k2 = 1;

    // rigth part
    for (int i = (s.size()/2) + 1; i < s.size(); i++)
    {
        if(c_ant == s[i]){
            k2++;
            if(k2 == k){
                if(s[i] == '1'){
                    s[i] = '0';
                    c_ant = '0';
                }else{
                    s[i] = '1';
                    c_ant = '1';
                }
                k2 = 1;
                count++;
            }else{
                c_ant = s[i];
            }
        }else{
            c_ant = s[i];
            k2 = 1;
        }
    }

    // left part
    c_ant = s[0]; 
    k2 = 1;
    for (int i = 0; i < s.size(); i++)
    {
        if(c_ant == s[i]){
            k2++;
            if(k2 == k){
                if(s[i] == '1'){
                    s[i] = '0';
                    c_ant = '0';
                }else{
                    s[i] = '1';
                    c_ant = '1';
                }
                k2 = 1;
                count++;
            }else{
                c_ant = s[i];
            }
        }else{
            c_ant = s[i];
            k2 = 1;
        }
    }
    
    res.first = count ;
    res.second = s;
    return res;
}



bool verifyLeftOnes(string s){
    
    for (int i = 0; i < (s.size() / 2); i++)
    {
        if (s[i] == '0')
        {
            return false;
        }    
    }
    
    return true;
}

bool verifyRigthOnes(string s){
    
    for (int i = (s.size() / 2); i < s.size(); i++)
    {
        if (s[i] == '0')
        {
            return false;
        }    
    }
    
    return true;
}

bool verifyRigthZeros(string s){
    
    for (int i = (s.size() / 2); i < s.size(); i++)
    {
        if (s[i] == '1')
        {
            return false;
        }    
    }
    
    return true;
}

bool verifyLeftZeros(string s){
    
    for (int i = 0; i < (s.size() / 2); i++)
    {
        if (s[i] == '1')
        {
            return false;
        }    
    }
    
    return true;
}

int main(){
    Fast

    int k; string s;

    cin >> k >> s;

    if(s.size() % 2 == 0){
        if(k <= (s.size()/2)){
            pair<int, string> res = applyOperationsInOrder(s,k);
            pair<int, string> res2 = applyOperationsInReverseOrder(s,k);
            pair<int, string> res3 = applyOperationsInOrder2(s,k);

            if (res2.first <= res.first)
            {
                cout << res2.first << " " << res2.second << "\n";
            }else{
                cout << res.first << " " << res.second << "\n";
            }
        }else{
            pair<int, string> res3 = applyOperationsInOrder2(s,k);
            pair<int, string> res = applyOperationsInOrder(s,k);
            if (res3.first <= res.first)
            {
                cout << res3.first << " " << res3.second << "\n";
            }else{
                cout << res.first << " " << res.second << "\n";
            }
        }
        
    }else{
        pair<int, string> res3 = applyOperationsInOrder2(s,k);
        pair<int, string> res = applyOperationsInOrder(s,k);
        if (res3.first <= res.first)
            {
                cout << res3.first << " " << res3.second << "\n";
            }else{
                cout << res.first << " " << res.second << "\n";
            }
    }
    
    return 0;
}