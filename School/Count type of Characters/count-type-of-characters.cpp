//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        vector <int> count (string s)
        {
            int up=0;
            int low=0;
            int spec=0;
            int num=0;
            
            for(int i=0; i<s.length(); i++)
            {
                if(s[i]>='a' and s[i]<='z') low++;
                else if(s[i]>='A' and s[i]<='Z') up++;
                else if(s[i]>='0' and s[i]<='9') num++;
                else spec++;
            }
            
            return {up,low,num,spec};
        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        vector <int> res = ob.count (s);
        for (int i : res)
            cout << i << '\n';
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends