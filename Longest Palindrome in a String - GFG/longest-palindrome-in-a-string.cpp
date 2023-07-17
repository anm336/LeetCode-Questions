//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string longestPalin (string S) {
        // code here
        int n = S.size();
        string ans;
        int len = 0;
        for(int i=0;i<n;i++){
            //For odd length
            int l = i, r = i;
            while(l>=0 && r<n && S[l]==S[r]){
                if(r-l+1 > len){
                    len = r-l+1;
                    ans = S.substr(l, r-l+1);
                }
                l--;
                r++;
            }
            //For even length
            l = i, r = i+1;
            while(l>=0 && r<n && S[l]==S[r]){
                if(r-l+1 > len){
                    len = r-l+1;
                    ans = S.substr(l, r-l+1);
                }
                l--;
                r++;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends