#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

bool visited[10000];
class Solution{
	public:
	
	void topo(int current,vector<int> adj[],bool visited[],stack<int>& st){
	    
	    vector<int>  :: iterator it;
	    visited[current] = true;
	    for(it = adj[current].begin(); it != adj[current].end(); it++){
	        if(!visited[*it]){
	            topo(*it,adj,visited,st);
	        }
	    }
	    st.push(current);
	}
	
	vector<int> topoSort(int V, vector<int> adj[]) {
	    // code here
	    vector<int> result;
	    bool visited[V];
	    stack<int> st;
	    
	    for(int i = 0; i < V;i++){
	        visited[i] = false;
	    }
	    
	    for(int i = 0; i < V; i++){
	        if(!visited[i]){
	            topo(i,adj,visited,st);
	        }
	    }
	    while(!st.empty()){
	        result.push_back(st.top());
	        st.pop();
	    }
	    
	   
	    return result;
	    
	}
};

// { Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}  // } Driver Code Ends