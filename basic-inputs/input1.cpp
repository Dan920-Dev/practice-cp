#include <iostream>

using namespace std;

int main()
{
    int TC, a, b;
    cin >> TC; // Read the number of test cases

    // Main loop to process each test case
    while (TC--)
    {
        cin >> a >> b; // Read the numbers 'a' and 'b'
        cout << a + b << "\n"; // Print the sum of 'a' and 'b' followed by a newline
    }
    return 0; // Indicates that the program has executed successfully
}
