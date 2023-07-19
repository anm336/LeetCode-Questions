class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b){
        //if(a[1]==b[1]) return a[0]<b[0];
        return a[1]<b[1];
    }
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int ans = 0;
        sort(intervals.begin(), intervals.end(), comp);
        
        int n = intervals.size();
        int end = INT_MIN;
        for(int i=0;i<n;i++){
            if(intervals[i][0]>=end){
                end = intervals[i][1];
            }
            else ans++;
        }
        
        return ans;
    }
};