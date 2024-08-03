//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    void bfs(vector<int>& visited, vector<int>& solution, vector<int> adjlist[], int node)
    {
        queue<int> q;
        q.push(node);
        
        visited[node]=true;
        
        while(!q.empty())
        {
            int front = q.front();
            solution.push_back(front);
            q.pop();
            
            for(auto i: adjlist[front])
            {
                if(!visited[i])
                {
                    visited[i]=true;
                    q.push(i);
                }
            }
        }
        
    }
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        // map<int,vector<int>> adjlist;
        
        // for(int i=0; i<V; i++)
        // {
        //     for(int j=0; j<adj[i].size(); j++)
        //     {
        //         adjlist[i].push_back(adj[i][j]);
        //         adjlist[adj[i][j]].push_back(i);
        //     }
        // }
        
        
        vector<int> visited(V,0);
        vector<int> solution;
        
        // for(int i=0; i<V; i++)
        // {
        //     if(!visited[i])
        //     {
        //         bfs(visited,solution,adj,i);
        //     }
        // }
        
         bfs(visited,solution,adj,0);
        
        return solution;
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends