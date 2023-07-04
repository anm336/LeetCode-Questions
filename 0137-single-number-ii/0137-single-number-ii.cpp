class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        //Bit Mnipulation, using 32 bits
        //For each of the numbers consider bit at a time from 0-32
        //Now if for a position we get sum of 1 bits at a pos. multiple of 3, 
        //Thta means the number occurs three times
        //Else that bit 1 belongs to the answer
        
        for(int i=0;i<32;i++){
            int sum = 0;
            
            for(int j=0;j<nums.size();j++){
                if((nums[j]>>i) & 1 == 1){
                    sum++;
                    sum%=3;
                }
            }
            if(sum==1){
                ans |= 1<<i;
            }
        }
        
//         unordered_map<int, int> m;
        
//         for(int i=0;i<n;i++){
//             m[nums[i]]++;
//         }
//         for(auto x: m){
//             if(x.second == 1) ans = x.first;
//         }
        
        return ans;
    }
};