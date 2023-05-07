//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        int ans = 0;
        unordered_map<int, int> mapping;
        for(int i=0;i<n;i++){
            mapping[arr[i]]++;
        }
        for(int i=0;i<n;i++){
            int x = arr[i];
            if(mapping[x]>0){
                int y = k-x;
                if(mapping[y]>0){
                    if(x==y){
                        ans+=(mapping[x]*(mapping[x]-1))/2;
                        mapping[x] = 0;
                    }
                    else{
                        ans+=mapping[x]*mapping[y];
                        mapping[x] = 0;
                        mapping[y] = 0;
                    }
                }
            }
        }
        return ans;
        // code here
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getPairsCount(arr, n, k);
        cout << ans << "\n";
    }
    
    return 0;
}
// } Driver Code Ends