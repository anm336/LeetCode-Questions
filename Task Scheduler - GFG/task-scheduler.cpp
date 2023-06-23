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
                cnt=1;
            }
            else if(x.second==maxi)cnt++;
        }
        
        //For max frequency
        //(maxi-1) is for all occurences of max freq element except last one
        //(K+1) is to denote the size of a block after which again max freq element can appear, no sooner than it
        //(cnt) at last denotes count of max elements at tail of processes as further there will be no process, so no need to take care of cooldown
        int intervals = (maxi-1)*(K+1)+cnt;
        int ans = max(N, intervals);
        
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