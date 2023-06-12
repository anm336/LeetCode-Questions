//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    string smallestNumber(int S, int D){
        // code here
        if(9*D < S) return "-1";
        string ans = "";
        if(D==1) return to_string(S);
        
        int x;
        while(D>1){
            int aval = S-1;
            if(aval>=9){
                x = 9;
            }
            else{
                x = aval;
            }
            ans+=to_string(x);
            S-=x;
            D--;
        }
        ans+=to_string(S);
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int S,D;
        cin >> S >> D;
        Solution ob;
        cout << ob.smallestNumber(S,D) << endl;
    }
    return 0; 
} 
// } Driver Code Ends