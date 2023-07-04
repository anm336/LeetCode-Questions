//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
    bool isValid(string s){
        if(s[0]=='0') return false;
        int x = stoi(s);
        if(x>255) return false;
        
        return true;
    }
    
    void func(string s, int i, int parts, string temp, vector<string> &ans){
        if(i==s.size() || parts==4){
            if(i==s.size() && parts==4) ans.push_back(temp.substr(0, temp.size()-1));
            return;
        }
        
        func(s, i+1, parts+1, temp+s[i]+".", ans);
        if(i+2<=s.size() && isValid(s.substr(i, 2))){
            func(s, i+2, parts+1, temp+s.substr(i, 2)+".", ans);
        }
        if(i+3<=s.size() && isValid(s.substr(i, 3))){
            func(s, i+3, parts+1, temp+s.substr(i, 3)+".", ans);
        }
    }
    
    vector<string> genIp(string &s) {
        // Your code here
        vector<string> ans;
        if(s.size()>12) return ans;
        
        func(s, 0, 0, "", ans);
        
        return ans;
    }

};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;

        /*generating naively*/
        Solution obj;
        vector<string> str = obj.genIp(s);
        sort(str.begin(), str.end());
        if(str.size()==0)
            cout << -1 << "\n";
        else{
            for (auto &u : str) {
                cout << u << "\n";
            }
        }
    }
}
// } Driver Code Ends