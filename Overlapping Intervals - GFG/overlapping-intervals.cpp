//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
         // Code here
         sort(intervals.begin(), intervals.end());
         vector<vector<int>> ans;
         int fi = intervals[0][0];
         int li = intervals[0][1];
         
         int n = intervals.size();
         for(int i=1;i<n;i++){
             int tempf = intervals[i][0];
             int templ = intervals[i][1];
             
             if(tempf>li){
                 ans.push_back({fi, li});
                 fi = tempf;
                 li = templ;
             }
             else{
                 fi = min(fi, tempf);
                 li = max(li, templ);
             }
         }
         ans.push_back({fi, li});
         
         return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>Intervals(n);
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			Intervals[i].push_back(x);
			Intervals[i].push_back(y);
		}
		Solution obj;
		vector<vector<int>> ans = obj.overlappedInterval(Intervals);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends