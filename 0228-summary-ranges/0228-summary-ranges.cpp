class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        vector<string> ans;
        if(n==0) return ans;
        else if(n==1){
            ans.push_back(to_string(nums[0]));
            return ans;
        }
        string s = to_string(nums[0]);
        int cntr = 0;
        for(int i=1;i<n;i++){
            int x;
            if(nums[i]==nums[i-1]+1){
                x = nums[i];
                cntr++;
                if(i==n-1){
                    s+="->";
                    s+=to_string(x);
                    ans.push_back(s);
                }
            }
            else{
                if(cntr != 0){
                    s+="->";
                    s+=to_string(x);
                    ans.push_back(s);
                    cntr=0;
                }
                else{
                    ans.push_back(s);
                }
                s = to_string(nums[i]);
                if(i==n-1) ans.push_back(s);
            }
        }
        return ans;
    }
};