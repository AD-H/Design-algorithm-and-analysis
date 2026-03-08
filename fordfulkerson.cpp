#include <iostream>
using namespace std;

int graph[20][20];
int visited[20];
int n;

int min(int a, int b){
    if(a < b){
        return a;
    }
    else{
        return b;
    }
}

int dfs(int u, int t, int flow){
    if(u == t){
        return flow;
    }
    visited[u] = 1;

    for(int v = 0; v < n; v++){
        if(!visited[v] && graph[u][v] > 0){
            int curr_flow = min(flow, graph[u][v]);
            int temp = dfs(v, t, curr_flow);

            if(temp > 0){
                graph[u][v] -= temp;
                graph[v][u] += temp;
                return temp;
            }
        }
    }
    return 0;
}

int fordFulkerson(int s, int t){
    int max_flow = 0;

    while(true){
        for(int i = 0; i < n; i++){
            visited[i] = 0;
        }

        int flow = dfs(s, t, 9999);

        if(flow == 0){
            break;
        }
        max_flow += flow;
    }

    return max_flow;
}

int main(){
    int s, t;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter capacity matrix:\n";
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> graph[i][j];

    cout << "Enter source: ";
    cin >> s;

    cout << "Enter sink: ";
    cin >> t;

    int maxFlow = fordFulkerson(s, t);

    cout << "Maximum Flow = " << maxFlow << endl;
    cout << "Flow out of source = Flow into sink = " << maxFlow << endl;
    return 0;
}
