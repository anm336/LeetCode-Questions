//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    static bool comp(pair<int,int> a, pair<int,int> b){
        return a.second < b.second;
    }
    
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int, int>> meets;
        
        for(int i=0;i<n;i++){
            meets.push_back({start[i], end[i]});
        }
        
        sort(meets.begin(), meets.end(), comp);
        
        int ans = 1;
        int endtime = meets[0].second;
        
        for(int i=1;i<n;i++){
            if(meets[i].first > endtime){
                ans++;
                endtime = meets[i].second;
            }
        }
        
        return ans;
        // Your code here
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends