//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool dfs(vector<int>& visited, vector<int>& pVisited, 
    vector<int> adj[], vector<int>& check, int node)
    {
        visited[node]=true;
        pVisited[node]=true;
        
        for(auto i:adj[node])
        {
            if(!visited[i])
            {
                if(!dfs(visited,pVisited,adj,check,i)) return false;
            }
            else if(pVisited[i]) return false;
        }
        
        check[node]=true;
        pVisited[node]=false;
        
        return true;
    }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        
        vector<int>visited(V,0);
        vector<int>path(V,0);
        vector<int> check(V,0);
        
        for(int i=0; i<V; i++)
        {
            if(!visited[i])
            {
                dfs(visited,path,adj,check,i);
            }
        }
        
        vector<int> solution;
        
        for(int i=0; i<V; i++)
        {
            if(check[i]) solution.push_back(i);
        }
        
        return solution;
    }
    
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends