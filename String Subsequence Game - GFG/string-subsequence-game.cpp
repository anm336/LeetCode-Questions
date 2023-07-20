//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    bool isVowel(char ch){
        return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u';
    }
    
    void func(int i, int last, string temp, string &S, int n, set<string> &ans){
        if(i==n){
            if(last==1) ans.insert(temp);
            return;
        }
        
        //take options
        if(last==-1){
            if(isVowel(S[i])){
                temp.push_back(S[i]);
                func(i+1, 0, temp, S, n, ans);
                temp.pop_back();
            }
        }
        else{
            if(isVowel(S[i])){
                temp.push_back(S[i]);
                func(i+1, 0, temp, S, n, ans);
                temp.pop_back();
            }
            else{
                temp.push_back(S[i]);
                func(i+1, 1, temp, S, n, ans);
                temp.pop_back();
            }
        }
        //Not taking
        func(i+1, last, temp, S, n, ans);
    }
    
    set<string> allPossibleSubsequences(string S) {
        // code here
        int n = S.size();
        set<string> ans;
        string temp = "";
        
        func(0, -1, temp, S, n, ans);
        
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
        set<string> ans = ob.allPossibleSubsequences(S);
        if (ans.size() == 0)
            cout << -1 << endl;
        else {
            for (auto i : ans) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// } Driver Code Ends