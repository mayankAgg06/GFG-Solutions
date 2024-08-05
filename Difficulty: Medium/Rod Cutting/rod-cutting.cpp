//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int findPrice(int price[], int ind, int n,vector<vector<int>>& dp)
    {
        if(ind==0) return price[ind]*n;
        
        if(dp[ind][n]!=-1) return dp[ind][n];
        
        int notPick = findPrice(price,ind-1,n,dp);
        
        int pick = INT_MIN;
        
        int rodLength=ind+1;
        
        if(rodLength<=n) pick = price[ind] + findPrice(price,ind,n-rodLength,dp);
        
        return dp[ind][n] = max(pick,notPick);
        
    }
    int cutRod(int price[], int n) {
        
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        
        return findPrice(price,n-1,n, dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends