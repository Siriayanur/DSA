#include<bits/stdc++.h>
using namespace std;

int dfsMemoized(int src,int dst,int k,int dp[100][102],vector<pair<int, int>> graph[]){
        if(k < 0){
            return INT_MAX;
        }
        if(src == dst){
            return 0;
        }
        if(dp[src][k] != -1){
            return dp[src][k];
        }

        int ans = INT_MAX;
        for (int i = 0; i < graph[src].size(); i++){
            int current = dfsMemoized(graph[src][i].first, dst, k - 1, dp, graph);
            ans = min(ans, (current == INT_MAX) ? current : current + graph[src][i].second);
        }
        return dp[src][k] = ans;
    }

    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {

        int numberOfFlights = flights.size();
        vector<pair<int, int>> graph[n];
        int dp[100][102];
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < numberOfFlights; i++)
        {
            graph[flights[i][0]].push_back(make_pair(flights[i][1], flights[i][2]));
        }
        int ans = dfsMemoized(src, dst, k + 1, dp, graph);
        if(ans == INT_MAX) return -1;
        return ans;
    }

int main(){
    int n;
    cin >> n ;
    vector<vector<int>> flights(((n * (n - 1))/2));
    int size = 0;
    int i = 0;
    while(1){
        int s, e, cost;
        cin >> s >> e >> cost;
        if (s < 0 || i >= (n * (n-1)/2))
            break;
        flights[i].push_back(s);
        flights[i].push_back(e);
        flights[i++].push_back(cost);
        size++;
    }

    int src;
    int dst;
    int k;
    cin >> src >> dst >> k;
    findCheapestPrice(n, flights, src, dst, k);
    for (int k = 0; k < size; k++)
    {
        for (int j = 0; j < 3; j++){
            cout << flights[k][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
// 3
// [[0,1,100],[1,2,100],[0,2,500]]
// 0
// 2
// 1