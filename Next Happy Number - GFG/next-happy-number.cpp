//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    unordered_map<int,int> nums;
    bool isHappy(int n){
        if(n==1) return true;
        if(nums.find(n)!=nums.end()) return false;
        nums[n]++;
        
        int val = 0;
        while(n>0){
            int x = n%10;
            val += (x*x);
            n/=10;
        }
        return isHappy(val);
    }
    int nextHappy(int N){
        // code here
        while(true){
            if(isHappy(++N)) return N;
        }
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.nextHappy(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends