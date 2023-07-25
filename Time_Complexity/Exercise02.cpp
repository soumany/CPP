#include <iostream>
using namespace std;

// Function to calculate the sum using a slow solution
int calculateSumSlow(int n) {
    int total = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            total += j;
        }
    }
    return total;
}

// Function to calculate the sum using a fast solution
int calculateSumFast(int n) {
    int total = (n * (n + 1)) / 2;
    return total;
}

// Function to display the result
void displayResult(int n, int sum, const string& method) {
    cout << "The sum of 1 to " << n << " (" << method << ") is " << sum << endl;
}

int main() {
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;

    // Calculate sum using slow solution
    int sumSlow = calculateSumSlow(n);
    displayResult(n, sumSlow, "slow");

    // Calculate sum using fast solution
    int sumFast = calculateSumFast(n);
    displayResult(n, sumFast, "fast");

    return 0;
}
