#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <climits>

using namespace std;

// Function to compute the minimum number of multiplications needed
int minmult(int n, const vector<int>& d, vector<vector<int>>& p) {
    vector<vector<int>> m(n + 1, vector<int>(n + 1, 0));

    for (int diag = 1; diag <= n - 1; diag++) {
        for (int i = 1; i <= n - diag; i++) {
            int j = i + diag;
            m[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++) {
                int cost = m[i][k] + m[k + 1][j] + d[i - 1] * d[k] * d[j];
                if (cost < m[i][j]) {
                    m[i][j] = cost;
                    p[i][j] = k;
                }
            }
        }
    }
    return m[1][n];
}

// Function to print the optimal parenthesization order
void order(int i, int j, const vector<vector<int>>& p) {
    if (i == j) {
        cout << "A" << i;
    } else {
        cout << "(";
        order(i, p[i][j], p);
        order(p[i][j] + 1, j, p);
        cout << ")";
    }
}

int main() {
    srand(time(0));

    // Get random number of matrices
    cout << "Enter n to generate a random number between 1-n: ";
    int n;
    cin >> n;
    int f = rand() % n + 1;
    if (f < 1) f = 1;  // Ensure at least one matrix

    cout << "Number of matrices: " << f << endl;

    // Get random dimensions for matrices
    cout << "Enter m for random matrix dimension numbers: ";
    int m;
    cin >> m;

    vector<int> d(f + 1);
    for (int i = 0; i <= f; i++) {
        d[i] = rand() % m + 1;
    }

    // Print matrix dimensions
    for (int i = 0; i <= f; i++) {
        cout << "d[" << i << "] = " << d[i] << endl;
    }

    // Compute the minimum multiplications
    vector<vector<int>> p(f + 1, vector<int>(f + 1, 0));
    int mi = minmult(f, d, p);

    cout << "Minimum number of multiplications needed: " << mi << endl;
    cout << "Optimal parenthesization order: ";
    order(1, f, p);
    cout << endl;

    return 0;
}
