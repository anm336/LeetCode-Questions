//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

//Back-end complete function Template for C++

class Solution{
    public:
    bool isScrambled(string s1, string s2, unordered_map<string, bool> &dp){
        if(s1==s2){
            return true;
        }
        
        string key = s1+"*"+s2;
        if(dp.find(key) != dp.end()) return dp[key];
        int n = s1.size();
        bool ans = false;
        for(int i=1;i<n;i++){
            //Swapped
            if(isScrambled(s1.substr(0, i), s2.substr(n-i, i), dp) && isScrambled(s1.substr(i, n-i), s2.substr(0, n-i), dp)){
                ans|=true;
                break;
            }
            
            //Not swapped
            if(isScrambled(s1.substr(0, i), s2.substr(0, i), dp) && isScrambled(s1.substr(i, n-i), s2.substr(i, n-i), dp)){
                ans|=true;
                break;
            }
        }

        return dp[key] = ans;
    }
    
    bool isScramble(string S1, string S2){
        //code here
        unordered_map<string, bool> dp;
        return isScrambled(S1, S2, dp);
    }    
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        string S1, S2;
        cin>>S1>>S2;
        Solution ob;
        
        if (ob.isScramble(S1, S2)) {
            cout << "Yes";
        }
        else {
            cout << "No";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends