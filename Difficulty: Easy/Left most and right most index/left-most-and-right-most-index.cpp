//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    
    long firstInd(vector<long long> v, long long x)
    {
        int start=0;
        int end=v.size()-1;
        long result=-1;
        
        int mid= start + (end-start)/2;
        
        while(start<=end)
        {
            mid= start + (end-start)/2;
            
            if(v[mid]==x)
            {
                result=mid;
                end=mid-1;
            }
            else if(v[mid]<x) start=mid+1;
            
            else end=mid-1;
            
        }
        
        return result;
    }
    
    long secondInd(vector<long long> v, long long x)
    {
        int start=0;
        int end=v.size()-1;
        long result=-1;
        
        int mid= start + (end-start)/2;
        
        while(start<=end)
        {
            mid= start + (end-start)/2;
            
            if(v[mid]==x)
            {
                result=mid;
                start=mid+1;
            }
            else if(v[mid]<x) start=mid+1;
            
            else end=mid-1;
        }
        return result;
    }
    pair<long,long> indexes(vector<long long> v, long long x)
    {
        long first = firstInd(v,x);
        long second = secondInd(v,x);
        
        return {first,second};
    }
};

//{ Driver Code Starts.

int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        vector<long long>v;
        cin>>n;
        for(long long i=0;i<n;i++)
        {
            cin>>k;
            v.push_back(k);
        }
        long long x;
        cin>>x;
        Solution obj;
        pair<long,long> pair = obj.indexes(v, x);
        
        if(pair.first==pair.second and pair.first==-1)
        cout<< -1 <<endl;
        else
        cout<<pair.first<<" "<<pair.second<<endl;

    }
	return 0;
}

// } Driver Code Ends