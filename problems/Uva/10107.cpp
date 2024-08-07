// What is the Median?

// https://onlinejudge.org/external/101/10107.pdf

#include <bits/stdc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); 
    cout.tie(nullptr);
    
    vector<long long> nums;
    long long  x;

    while(cin >> x){
        nums.push_back(x);
        sort(nums.begin(), nums.end());

        if(nums.size() % 2 == 0){
            cout << (nums[(nums.size()/2) - 1] + nums[nums.size()/2]) / 2 << "\n";
        }else{
            cout << nums[floor(nums.size()/2)] << "\n";
        }
    
    }
    return 0;
}
