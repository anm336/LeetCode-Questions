class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int canbedone = 0;
        int i = 0;
        int zers = 0;
        int ans = 0;
        int size = flowerbed.size();
        while(i<size && flowerbed[i]==0){
            zers++;
            i++;
        }
        if(i==size){
            if(zers==1 || zers==2) ans = 1;
            else{
                if(zers%2==0) ans+=zers/2;
                else ans+=(zers/2+1);
            }
            zers=0;
        }
        else{
            ans+=zers/2;
            zers=0;
        }
        while(i<size){
            if(flowerbed[i]==0){
                zers++;
            }
            else{
                if(zers>2){
                    if(zers%2!=0) ans+=zers/2;
                    else ans+=(zers-1)/2;
                }
                zers=0;
            }
            i++;
        }
        if(zers>1){
            ans+=zers/2;
        }
        return ans>=n;
    }
};