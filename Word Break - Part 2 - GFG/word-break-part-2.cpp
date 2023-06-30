//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void func(string A, unordered_map<string, int> &dict, string &temp, vector<string> &ans){
        if(dict.find(A) != dict.end()){
            string curr = temp;
            temp+=A;
            ans.push_back(temp);
            temp = curr;
        }
        
        for(int j=1; j<A.size(); j++){
            string str = A.substr(0, j);
            //cout<<str<<endl;
            if(dict.find(str) != dict.end()){
                string curr = temp;
                temp += str;
                temp += " ";
                //cout<<temp<<endl;
                func(A.substr(j, A.size()-j), dict, temp, ans);
                temp = curr;
                // ans |= func(A.substr(j, A.size()-j), dict, dp);
                // if(ans) break;
            }
        }
        
        return;
    }
    
    vector<string> wordBreak(int n, vector<string>& dicti, string s)
    {
        // code here
        vector<string> ans;
        //int n = A.size();
        //int m = B.size();
        
        unordered_map<string, int> dict;
        for(auto x: dicti) dict[x]++;
        
        string temp = "";
        func(s, dict, temp, ans);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends