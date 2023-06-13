//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    bool allocated(int A[], int pages, int N, int M){
        int stucnt = 1;
        int pagecnt = 0;
        
        for(int i=0;i<N;i++){
            if(A[i] + pagecnt <= pages){
                pagecnt += A[i];
            }
            else{
                stucnt++;
                if(stucnt > M || A[i] > pages) return false;
                pagecnt = A[i];
            }
        }
        
        return true;
    }
    
    int findPages(int A[], int N, int M) 
    {
        //code here
        if(M>N) return -1;
        int sum = 0;
        for(int i=0;i<N;i++) sum+=A[i];
        
        int s=0;
        int e=sum;
        int ans = -1;
        int mid;
        
        while(s<=e){
            mid = (e-s)/2 + s;
            if(allocated(A, mid, N, M)){
                e = mid-1;
                ans = mid;
            }
            else{
                s=mid+1;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends