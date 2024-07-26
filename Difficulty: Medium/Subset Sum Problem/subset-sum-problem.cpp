//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool checkSum(vector<int> arr, int target, int ind, vector<vector<int>>& dp)
    {
        if(target==0) return dp[ind][target] = true;
        if(ind==0) return (arr[ind]==target);
        
        if(dp[ind][target]!=-1) return dp[ind][target];
        
        bool pick = false;
        if(target>=arr[ind]) pick = checkSum(arr,target-arr[ind],ind-1,dp);
        
        bool notPick = checkSum(arr,target,ind-1,dp);
        
        return dp[ind][target] = (pick || notPick);
            
    }
    bool isSubsetSum(vector<int>arr, int sum){
        
        int n= arr.size();
        vector<vector<int>> dp(n,vector<int>(sum+1, -1));
        return checkSum(arr,sum, n-1,dp);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends