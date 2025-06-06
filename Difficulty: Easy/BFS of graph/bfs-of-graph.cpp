class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    void bfsTraversal(vector<vector<int>> &adj, vector<int> &visited, vector<int> &solution, int start)
    {
        queue<int> q;
        
        q.push(start);
        visited[start]=1;
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            
            solution.push_back(node);
            
            for(auto children:adj[node])
            {
                if(!visited[children]) {
                    q.push(children);
                    visited[children]=1;
                }
            }
        }
    }
    
    vector<int> bfs(vector<vector<int>> &adj) {
        // Code here
        
        
        int n= adj.size();
        vector<int> visited(n,0);
        
        vector<int> solution;
        
        for(int i=0; i<n; i++)
        {
            if(!visited[i])
            {
                bfsTraversal(adj,visited,solution,i);
            }
        }
        
        return solution;
    }
};