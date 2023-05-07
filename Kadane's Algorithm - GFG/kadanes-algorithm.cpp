//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n){
        long long ans = 0;
        long long tempsum = 0;
        for(int i=0;i<n;i++){
            tempsum+=arr[i];
            if(tempsum<0) tempsum = 0;
            ans = max(ans, tempsum);
        }
        if(ans==0){
            long long negmax = arr[0];
            for(int i=1;i<n;i++){
                negmax = max(negmax, arr[i]*1LL);
            }
            return negmax;
        }
        return ans;
        // Your code here
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}

// } Driver Code Ends