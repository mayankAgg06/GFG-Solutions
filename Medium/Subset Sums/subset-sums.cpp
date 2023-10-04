//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    void SubsetSum(vector<int> arr, int N, int i, vector<int>&ans, int sum)
    {
        if(i==N)
        {
            ans.push_back(sum);
            return;
        }
        
        SubsetSum(arr,N,i+1,ans,sum+arr[i]);
        SubsetSum(arr,N,i+1,ans,sum);
        
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        if(N==1)return {0,arr[0]};
        
        vector<int> ans;
        
        SubsetSum(arr,N,0,ans,0);
        
        return ans;
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends