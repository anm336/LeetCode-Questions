//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	    long long ans = 0;
	    long long prod = 1;
	    long long maxel = *max_element(arr.begin(), arr.end()); 
	    for(int i=0;i<n;i++){
	        if(arr[i]!=0){
	            prod*=arr[i];
	            ans = max(ans, prod);
	        }
	        else prod = 1;
	        
	    }
	    
	    prod = 1;
	    for(int i=n-1;i>=0;i--){
	        if(arr[i]!=0){
	            prod*=arr[i];
	            ans = max(ans, prod);
	        }
	        else prod = 1;
	        
	    }
	    
	    if(ans<=0) return maxel;
	    else return ans;
	    // code here
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends