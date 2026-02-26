#include <iostream>
#include <string>
using namespace std;

int max(int a, int b) {
    return (a > b) ? a : b;
}
void subseqLen2(string s) {
    int n = s.length();
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            cout << s[i] << s[j] << " ";
        }
    }
}

int main() {
    string X, Y;
    cout << "Enter sequence X: ";
    cin >> X;
    cout << "Enter sequence Y: ";
    cin >> Y;

    int m = X.length();
    int n = Y.length();

    int dp[100][100];

    for(int i = 0; i <= m; i++) {
        for(int j = 0; j <= n; j++) {
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else if(X[i-1] == Y[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    int i = m, j = n;
    string lcs = "";

    while(i > 0 && j > 0) {
        if(X[i-1] == Y[j-1]) {
            lcs = X[i-1] + lcs;
            i--;
            j--;
        } else if(dp[i-1][j] > dp[i][j-1]) {
            i--;
        } else {
            j--;
        }
    }

    cout << "\nLength of LCS = " << dp[m][n];
    cout << "\nLCS = " << lcs;

    cout << "Subsequences of length 2 in X:\n";
    subseqLen2(X);
    cout << endl;
    cout << "Subsequences of length 2 in Y:\n";
    subseqLen2(Y);


    return 0;
}

