//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int checkRedundancy(string s) {
        // code here
        bool ans = false;
        
        int n = s.size();
        stack<char> stck;
        for(int i=0;i<n;i++){
            if(s[i]=='(' || s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/') stck.push(s[i]);
            else{
                if(s[i]==')'){
                    bool operators = false;
                    while(stck.top()=='+' || stck.top()=='-' || stck.top()=='*' || stck.top()=='/'){
                        operators = true;
                        stck.pop();
                    }
                    
                    if(!operators){
                        ans = true;
                        break;
                    }
                    stck.pop();
                }
            }
        }
        
        if(ans) return 1;
        return 0;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        
    
        string s; 
        cin>>s;
        
        Solution obj;
        int res = obj.checkRedundancy(s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends