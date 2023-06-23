//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int leastInterval(int N, int K, vector<char> &tasks) {
        // code here 
        unordered_map<char,int>mp;
        for(int i=0;i<N;i++)
        {
            mp[tasks[i]]++;
        }
        int maxi=0;int cnt=0;
        
        for(auto x: mp)
        {
            if(x.second>maxi)
            {
                maxi=x.second;
                cnt=0;
            }
            else if(x.second==maxi)cnt++;
        }
        
        if(N-maxi>(K*(maxi-1))) return N;
        int ans=maxi+K*(maxi-1)+(cnt);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<char> tasks(N);
        for (int i = 0; i < N; i++) cin >> tasks[i];

        Solution obj;
        cout << obj.leastInterval(N, K, tasks) << endl;
    }
    return 0;
}
// } Driver Code Ends