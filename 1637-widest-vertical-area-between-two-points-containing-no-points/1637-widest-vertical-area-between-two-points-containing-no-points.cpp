class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b){
        return a[0]!=b[0] ? a[0]<b[0] : a[1]<b[1];
    }
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        int ans = INT_MIN;
        int n = points.size();
        sort(points.begin(), points.end(), comp);
        
        for(int i=1;i<n;i++){
            ans = max(ans, points[i][0]-points[i-1][0]);
        }
        
        return ans;
    }
};