// Let’s Play Magic!

// https://onlinejudge.org/external/109/10978.pdf

#include <bits/stdc++.h>

using namespace std;

int main(){
    int n = 0, position_to_insert;
    string card, number;

    cin >> n;

    while (n != 0)
    {
        vector<string> cards(n,"");
        position_to_insert = -1;
        for (int i = 0; i < n; ++i)
        {
            cin >> card >> number;
            int s_n = number.size();
            while (s_n)
            {
                position_to_insert = (position_to_insert + 1) % n;
                if(cards[position_to_insert] == ""){
                    s_n--;
                }
            }
            cards[position_to_insert] = card;
        }

        for (int i = 0; i < cards.size(); i++)
        {
            cout << cards[i] << (i + 1 < cards.size()?" ":"\n");
        }
        cin >> n;
    }
    

    return 0;
}