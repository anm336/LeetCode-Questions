//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    bool possible(int arr[], long long mid, long long n, long long k){
        int pntrcnt = 1;
        int alloc = 0;
        
        for(int i=0;i<n;i++){
            if(arr[i] + alloc <= mid){
                alloc+=arr[i];
            }
            else{
                pntrcnt++;
                if(pntrcnt > k || arr[i] > mid) return false;
                alloc = arr[i];
            }
        }
        
        return true;
    }
    
    long long minTime(int arr[], int n, int k)
    {
        // code here
        // return minimum time
        
        long long s = 0;
        long long sum = 0;
        for(int i=0;i<n;i++) sum+=arr[i];
        long long e = sum;
        long long mid;
        long long ans = -1;
        
        while(s<=e){
            mid = (e-s)/2 + s;
            if(possible(arr, mid, n, k)){
                ans = mid;
                e = mid-1;
            }
            else s = mid+1;
        }
        
        return s;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}
// } Driver Code Ends