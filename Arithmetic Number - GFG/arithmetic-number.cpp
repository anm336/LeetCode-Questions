//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int inSequence(int A, int B, int C){
        //B = A + (n-1)*C;
        // code here
        int x = B-A;
        if(B>A){
            if(C<=0) return 0;
            else{
                if(x%C==0) return 1;
                else return 0;
            }
        }
        else if(A==B) return 1;
        else{
            if(C>=0) return 0;
            else{
                if(x%C==0) return 1;
                else return 0;
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int A, B, C;
        cin>>A>>B>>C;
        
        Solution ob;
        cout<<ob.inSequence(A, B, C)<<endl;
    }
    return 0;
}
// } Driver Code Ends