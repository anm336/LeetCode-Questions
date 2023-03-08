class Solution {
public:
    int func(vector<int>& piles, int k){
        int hrs = 0;
        for(int i=0;i<piles.size();i++){
            hrs += (piles[i]+k-1)/k;
        }
        return hrs;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        while(left < right){
            int mid = ((right-left)/2 + left);
            int x = func(piles, mid);
            if(x <= h){
                right = mid;
            }
            else{
                left = mid + 1;
            }
        }
        return left;
    }
};