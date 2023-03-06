class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int ans = 0;
        int n = arr.size();
        int i=1;
        int j=0;
        while(j<n && k>0){
            if(arr[j]!=i){
                ans = i;
                k--;
            }
            else{
                j++;
            }
            i++;
        }
        while(k>0){
            ans = i;
            i++;
            k--;
        }
        return ans;
    }
};