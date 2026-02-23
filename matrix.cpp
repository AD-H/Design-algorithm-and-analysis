#include <iostream>
using namespace std;

int min(int a, int b) {
    return (a < b) ? a : b;
}
int main() {
    int n;
    cout << "Enter number of matrices: ";
    cin >> n;

    int p[100];
    cout << "Enter dimensions array (size " << n+1 << "):\n";
    for(int i = 0; i <= n; i++) {
        cin >> p[i];
    }

    int m[100][100];

    for(int i = 1; i <= n; i++)
        m[i][i] = 0;

    for(int L = 2; L <= n; L++) {
        for(int i = 1; i <= n - L + 1; i++) {
            int j = i + L - 1;
            m[i][j] = 999999;   // infinity

            for(int k = i; k < j; k++) {
                int cost = m[i][k] + m[k+1][j]
                           + p[i-1] * p[k] * p[j];
                m[i][j] = min(m[i][j], cost);
            }
        }
    }

    cout << "\nMinimum number of scalar multiplications = "
         << m[1][n];

    return 0;
}

