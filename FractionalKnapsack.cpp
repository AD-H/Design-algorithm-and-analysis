#include <iostream>
using namespace std;

int main() {
    int n;
    float m;
    cout << "Enter number of objects: ";
    cin >> n;
    float p[n], w[n], d[n];
    cout << "Enter profits:\n";
    for (int i = 0; i < n; i++){
        cin >> p[i];
    }
    cout << "Enter weights:\n";
    for (int i = 0; i < n; i++){
        cin >> w[i];
    }
    cout << "Enter knapsack capacity: ";
    cin >> m;
    for (int i = 0; i < n; i++)
        d[i] = p[i] / w[i];
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (d[j] < d[j + 1]) {
                float temp = d[j];
                d[j] = d[j + 1];
                d[j + 1] = temp;

                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;

                temp = w[j];
                w[j] = w[j + 1];
                w[j + 1] = temp;
            }
        }
    }
    float totalProfit = 0.0;
    for (int i = 0; i < n && m > 0; i++) {
        if (w[i] <= m) {
            totalProfit += p[i];
            m -= w[i];
        } else {
            totalProfit += d[i] * m;
            m = 0;
        }
    }
    cout << "Maximum Profit = " << totalProfit << endl;
    return 0;
}
