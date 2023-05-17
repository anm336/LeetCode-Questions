//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        vector<int> ans;
        
        arr.insert(arr.begin(), 0);
        
        for(int i=1;i<=n;i++){
            int x = abs(arr[i]);
            if(arr[x]>0) arr[x] = -arr[x];
            else ans.push_back(x);
        }
        
        for(int i=1;i<=n;i++){
            if(arr[i]>0) ans.push_back(i);
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
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends