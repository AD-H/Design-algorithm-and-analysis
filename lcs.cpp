#include <bits/stdc++.h>
using namespace std;

int main() {
    string X, Y;
    cout << "Enter sequence X: ";
    cin >> X;
    cout << "Enter sequence Y: ";
    cin >> Y;

    int m = X.length();
    int n = Y.length();

    int dp[m+1][n+1];


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
            lcs.push_back(X[i-1]);
            i--; j--;
        } else if(dp[i-1][j] > dp[i][j-1])
            i--;
        else
            j--;
    }

    reverse(lcs.begin(), lcs.end());

    cout << "\nLength of LCS = " << dp[m][n] << endl;
    cout << "LCS = " << lcs << endl;

    return 0;
}
