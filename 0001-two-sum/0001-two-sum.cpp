class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int,int> map;
        for(int i=0;i<nums.size();i++){
            map[nums[i]]++;
        }
        for(int i=0;i<nums.size();i++){
            int y = target - nums[i];
            if(map[y]>0){
                int index_y = find(nums.begin(), nums.end(), y) - nums.begin();
                ans.push_back(index_y);
                map[y]--;
                if(map[nums[i]]>0 && i!=index_y){
                    ans.push_back(i);
                    break;
                }
                else{
                    ans.pop_back();
                    map[y]++;
                }
            }
        }
        return ans;
    }
};