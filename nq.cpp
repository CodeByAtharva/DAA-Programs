#include <iostream>
#include <cmath>
using namespace std;

int x[20]; // Global array to store the position of queens

// Function to check if a queen can be placed at (k, i)
bool Place(int k, int i) {
    for (int j = 1; j <= k - 1; j++) {
        if (x[j] == i || abs(x[j] - i) == abs(j - k))
            return false; // Same column or same diagonal
    }
    return true;
}

// Recursive function to solve N-Queens problem
void NQueens(int k, int n) {
    for (int i = 1; i <= n; i++) {
        if (Place(k, i)) {
            x[k] = i;
            if (k == n) {
                // Print one of the solutions
                cout << "[ ";
                for (int j = 1; j <= n; j++)
                    cout << x[j] << " ";
                cout << "]" << endl;
            } else {
                NQueens(k + 1, n);
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of queens: ";
    cin >> n;

    cout << "All possible solutions for " << n << " queens are:\n";
    NQueens(1, n);

    return 0;
}