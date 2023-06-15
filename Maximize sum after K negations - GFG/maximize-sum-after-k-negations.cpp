//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long int maximizeSum(long long int a[], int n, int k)
    {
        // Your code goes here
        sort(a, a+n);
        long long int ans = 0;
        int i=0;
        
        while(i<n){
            if(a[i]>=0 || k==0) break;
            a[i] = -a[i];
            i++;
            k--;
        }
        
        if(k!=0){
            if(k%2==0){
                for(int i=0;i<n;i++) ans+=a[i];
            }
            else{
                for(int i=0;i<n;i++) ans+=a[i];
                int z = *min_element(a, a+n);
                ans-=z;
                ans-=z;
            }
        }
        else{
            for(int i=0;i<n;i++) ans+=a[i];
        }
        
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
         int n, k;
         cin>>n>>k;
         long long int a[n+5];
         for(int i=0;i<n;i++)
         cin>>a[i];
         Solution ob;
         cout<<ob.maximizeSum(a, n, k)<<endl;
     }
	
	return 0;
}
// } Driver Code Ends