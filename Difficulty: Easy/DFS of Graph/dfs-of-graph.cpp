class Solution {
  public:
  void dfsTraversal(vector<vector<int>> &adj, vector<int> &visited, vector<int> &solution, int start)
    {
        visited[start]=1;
        solution.push_back(start);
        
        for(auto children: adj[start])
        {
            if(!visited[children])
            {
                dfsTraversal(adj,visited,solution,children);
            }
        }
        
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        
        int n= adj.size();
        vector<int> visited(n,0);
        
        vector<int> solution;
        
        for(int i=0; i<n; i++)
        {
            if(!visited[i])
            {
                dfsTraversal(adj,visited,solution,i);
            }
        }
        
        return solution;
    }
};