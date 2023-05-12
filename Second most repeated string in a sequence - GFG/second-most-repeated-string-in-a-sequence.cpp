//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
  public:
    string secFrequent (string arr[], int n)
    {
        unordered_map<string, int> mapping;
        for(int i=0;i<n;i++){
            mapping[arr[i]]++;
        }
        if(mapping.size()==1) return "";
        string ans;
        int val = INT_MIN;
        for(auto it :mapping){
            if(it.second>val){
                ans = it.first;
                val = it.second;
            }
        }
        mapping[ans] = INT_MIN;
        val = INT_MIN;
        for(auto it : mapping){
            if(it.second>val){
                ans = it.first;
                val = it.second;
            }
        }
        return ans;
        //code here.
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        Solution ob;
        cout << ob.secFrequent (arr, n) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends