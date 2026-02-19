#include<iostream>
using namespace std;
int main(){
    int n,m;
    cout << "Enter the number of elements:"<<endl;
    cin >> n;
    cout << "Enter the number of capacity of knapsack:"<<endl;
    cin >> m;
    int profit[n];
    int weight[n];
    cout << "Enter the profits:"<<endl;
    for(int i = 0;i<n;i++){
        cin >> profit[i];
    }
    cout << "Enter the weights:" <<endl;
    for(int i = 0;i<n;i++){
        cin >> weight[i];
    }
    int kn[n+1][m+1];
    for(int i = 0;i<=n;i++){
        for(int w = 0;w<=m;w++){
            if(i == 0||w == 0){
                kn[i][w] = 0;
            }
            else if(weight[i-1]<=w){
                kn[i][w] = max(profit[i-1]+kn[i-1][w-weight[i-1]],kn[i-1][w]);
            }
            else{
                kn[i][w] = kn[i-1][w];
            }
        }
    }
    cout << kn[n][m]<<endl;
    int w = m;
    for(int i = n;i>0 && w>0;i--){
        if(kn[i][w]!=kn[i-1][w]){
            cout << "item:"<< i << endl;
            w -= weight[i-1];
        }
    }
}
