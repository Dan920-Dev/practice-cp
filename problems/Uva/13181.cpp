// Sleeping in hostels

// https://onlinejudge.org/external/131/13181.pdf

#include <bits/stdc++.h>

using namespace std;

int left_count(int x_pos){
    return abs(1 - x_pos) - 1; 
}

int rigth_count(int x_pos, int size){
    return abs(size - x_pos) - 1;
}

int main(){

    string beds = "";
    int  l, r, res = 0;
    
    while (cin >> beds)
    {
        vector<int> pos;
        res = 0;

        for (int i = 0; i < beds.size(); i++)
        {
            if(beds[i] == 'X'){
                pos.push_back(i+1);
            }
        }
            if(pos.size() > 1){
                
                if(left_count(pos[0]) >= 0 && left_count(pos[0]) > res){
                    res = left_count(pos[0]);
                }

                if(rigth_count(pos[pos.size() - 1], beds.size()) >= 0 && rigth_count(pos[pos.size() - 1], beds.size()) > res){
                    res = rigth_count(pos[pos.size() - 1], beds.size());
                }
                
                for (int i = 1; i < pos.size(); i++){
                        int dif = pos[i] - pos[i - 1] - 1;
                        if(dif % 2 != 0 && dif > 1){
                            if(floor(dif/2) > res){
                                res = floor(dif/2);
                            }
                            
                        }
                        if(dif % 2 == 0 && dif > 2){
                            if((dif/2) - 1> res){
                            res = (dif/2) - 1;
                            }
                        }
                }
            }else{

                if(left_count(pos[0]) >= 0 && left_count(pos[0]) > res){
                    res = left_count(pos[0]);
                }

                if(rigth_count(pos[0], beds.size()) >= 0 && rigth_count(pos[0], beds.size()) > res){
                    res = rigth_count(pos[0], beds.size());
                }
                    
            }

            cout << res << "\n";
    }
    

    return 0;
}