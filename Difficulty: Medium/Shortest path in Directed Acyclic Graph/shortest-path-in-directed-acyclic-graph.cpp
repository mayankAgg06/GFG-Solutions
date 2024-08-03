//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
    private:
    void dfs(unordered_map<int,vector<pair<int,int>>>& adj, vector<int>& visited,stack<int>& st, int node)
    {
        visited[node]=true;
        
        for(auto it: adj[node])
        {
            if(!visited[it.first]) dfs(adj,visited,st,it.first);
        }
        
        st.push(node);
    }
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        unordered_map<int,vector<pair<int,int>>> adj;
        
        for(auto edge:edges)
        {
            adj[edge[0]].push_back({edge[1],edge[2]});
        }
        
        vector<int> visited(N,0);
        vector<int> distances(N,-1);
        stack<int> st;
        
        for(int i=0; i<N; i++)
        {
            if(!visited[i]) dfs(adj,visited,st,i);
        }
        
        distances[0]=0;
        
        while(!st.empty())
        {
            int topele = st.top();
            st.pop();
            
            if(distances[topele]!=-1)
            {
                for(auto it: adj[topele])
                {
                    if(distances[it.first]==-1 || distances[it.first] > distances[topele]+it.second)
                    {
                        distances[it.first] = distances[topele]+it.second;
                    }
                }
            }
        }
        
        return distances;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends