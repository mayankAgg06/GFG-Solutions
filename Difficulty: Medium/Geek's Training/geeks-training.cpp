//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    int findPoint(vector<vector<int>> & arr, int itr, int prev, vector<vector<int>>& dp)
    {
    	//Base Case
    	if(itr==0)
        {
        	int maxi = 0;
        	for(int i=0; i<=2; i++)
        	{
        		if(i!=prev) maxi = max(maxi,arr[itr][i]);
        	}
        	return dp[itr][prev]=maxi;
        }
        
        //dp
        if(dp[itr][prev]!=-1) return dp[itr][prev];
    
        //recurrence
        int maxi = 0;
        for(int i=0; i<=2; i++)
        {
        	if(i!=prev) maxi = max(maxi,arr[itr][i] + findPoint(arr,itr-1,i,dp));
        }
        
        return dp[itr][prev]=maxi;
    
    }


    int maximumPoints(vector<vector<int>>& arr, int n) {
        // Code here
        vector<vector<int>> dp(n,vector<int>(4,-1));
	
    	int maxi = 0;
        for(int i=0; i<=2; i++)
        {
            maxi = max(maxi,arr[n-1][i] + findPoint(arr,n-2,i,dp));
        }
        
        return maxi;

    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> arr;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            arr.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends