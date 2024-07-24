//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:

    string longestCommonPrefix(vector<string> arr) {
        
        string ans = arr[0];
        
        for(auto i: arr)
        {
            int ind=0;
            
            while(ind<i.length() and ind<ans.length() and i[ind]==ans[ind]) ind++;
            
            ans= ans.substr(0,ind);
        }
        
        if(ans.length()==0) return "-1";
        
        return ans;
        // your code here
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.longestCommonPrefix(arr) << endl;
    }
}

// } Driver Code Ends