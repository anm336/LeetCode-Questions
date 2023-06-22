//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool lemonadeChange(int N, vector<int> &bills) {
        // code here
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

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> bills(N);
        for (int i = 0; i < N; i++) cin >> bills[i];

        Solution obj;
        int ans = obj.lemonadeChange(N, bills);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends