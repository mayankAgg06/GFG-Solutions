//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void dfs( vector<int>& visited, vector<int>& solution, map<int,vector<int>>& adj, int node)
    {
        visited[node]=1;
        solution.push_back(node);
        
        for(auto i: adj[node])
        {
            if(!visited[i])
            {
                dfs(visited,solution,adj,i);
            }
        }
    }
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        map<int,vector<int>> adjlist;
        
        // for(int i=0; i<=V; i++)
        // {
        //     adjlist[adj[i][0]].push_back(adj[i][1]);
        //     adjlist[adj[i][1]].push_back(adj[i][0]);
        // }
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < adj[i].size(); j++) {
                adjlist[i].push_back(adj[i][j]);
                adjlist[adj[i][j]].push_back(i);
            }
        }
        
        vector<int> visited(V,0);
        vector<int> solution;
        
        for(int i=0; i<V; i++)
        {
            if(!visited[i])
            {
                dfs(visited,solution,adjlist,i);
            }
        }
        
        return solution;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends