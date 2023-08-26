//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
        unordered_map<char, int> freq;
        int n = s.size();
        int i=0, j=0;
        int ans = -1;
        
        while(j<n){
            freq[s[j++]]++;
            if(freq.size() == k){
                ans = max(ans, j-i);
            }
            while(freq.size() > k){
                int x = freq[s[i]];
                if(x==1){
                    freq.erase(s[i]);
                }
                else{
                    freq[s[i]]--;
                }
                i++;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends