// Template with runtime
#include <bits/stdc++.h>

using namespace std;

void solve() {
    // code solution
}

int main() {
     // Take the start time
    auto start = std::chrono::high_resolution_clock::now();

    ios_base::sync_with_stdio(false); // Disabling synchronization for faster I/O
    cin.tie(nullptr); // Unbinding cin from cout for faster I/O
    cout.tie(nullptr); // Unbinding cout from cin for faster I/O
    
    solve(); // Calling the function to solve the problem

    // Take the end time
    auto end = chrono::high_resolution_clock::now();

    // Calculate the duration in milliseconds
    auto duration = chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    // Display the elapsed time in milliseconds
    cout << "Time: " << duration << " milliseconds" << "\n";

    return 0;
}
