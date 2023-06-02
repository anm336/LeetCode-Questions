class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        
        int i = 0;
        while(i<n && nums[i] == 0) i++;
        if(i==n) return 0;
        
        int zc = 0;
        int oc = 0;
        vector<int> cnts;
        
        for(int j = i ; j<n ; j++){
            if(nums[j] == 1){
                if(zc!=0){
                    cnts.push_back(-zc);
                    zc = 0;
                }
                oc++;
            }
            else{
                if(oc!=0){
                    cnts.push_back(oc);
                    oc = 0;
                }
                zc++;
            }
        }
        if(zc!=0) cnts.push_back(zc);
        if(oc!=0) cnts.push_back(oc);
        
        if(cnts.size()==1){
            if(i==0) return cnts[0] - 1;
            else return cnts[0];
        }
        if(cnts.size()==2) return cnts[0];
        int ans = 0;
        for(int k=0;k<cnts.size()-2;k++){
            int x = cnts[k];
            int y = cnts[k+1];
            int z = cnts[k+2];
            
            if(y==-1){
                ans = max(ans, x+z);
            }
        }
        // for(int i=0;i<cnts.size();i++){
        //     cout<<cnts[i]<<" ";
        // }
        // cout<<endl;
        
        ans = max(ans, *max_element(cnts.begin(), cnts.end()));
        return ans;
    }
};