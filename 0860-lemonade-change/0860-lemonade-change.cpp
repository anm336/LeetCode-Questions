class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int N = bills.size();
        int fivec = 0, tenc = 0;
        
        for(int i=0;i<N;i++){
            if(bills[i] == 5){
                fivec++;
            }
            else if(bills[i] == 10){
                tenc++;
                if(fivec>0){
                    fivec--;
                }
                else{
                    return false;
                    break;
                }
            }
            else{
                if(tenc>0 && fivec>0){
                    tenc--;
                    fivec--;
                }
                else if(fivec>2){
                    fivec-=3;
                }
                else{
                    return false;
                    break;
                }
            }
        }
        
        return true;
    }
};