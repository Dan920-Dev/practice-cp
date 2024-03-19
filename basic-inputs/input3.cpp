#include <iostream>
using namespace std;

int main()
{
    int a, b;

    // Loop to continuously read pairs of integers from input until end-of-file
    while (cin >> a >> b)
    {
        cout << a + b << "\n"; // Print the sum of 'a' and 'b' followed by a newline
    }

    return 0; // Indicates that the program has executed successfully
}
