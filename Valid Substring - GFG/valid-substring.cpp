//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for c++
class Solution {
  public:
    int findMaxLen(string s) {
        // code here
        int n = s.size();
        stack<int> stck;
        
        for(int i=0;i<n;i++){
            if(stck.empty() || s[i]=='(') stck.push(i);
            else{
                if(s[stck.top()]=='(') stck.pop();
                else stck.push(i);
            }
        }
        
        
        int next = n;
        int ans = INT_MIN;
        while(!stck.empty()){
            int top = stck.top();
            //cout<<top<<endl;
            stck.pop();
            ans = max(ans, next-top-1);
            next = top;
        }
        ans = max(ans, next-0);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S; 
        Solution ob;
        cout << ob.findMaxLen(S) << endl;
    }
    return 0;
}

// } Driver Code Ends