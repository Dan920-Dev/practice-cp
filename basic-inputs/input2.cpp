#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b; // Read two integers 'a' and 'b' from input

    // Continue reading input and processing until 'a' and 'b' are both zero
    while (a || b)
    {
        cout << a + b; // Print the sum of 'a' and 'b'
        cin >> a >> b; // Read the next pair of integers 'a' and 'b' from input
    }

    return 0; // Indicates that the program has executed successfully
}
