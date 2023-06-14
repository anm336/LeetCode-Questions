//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int buyMaximumProducts(int n, int k, int price[]){
        //Write your code here
        vector<pair<int,int>> prices;
        
        for(int i=0;i<n;i++) prices.push_back({price[i], i+1});
        
        sort(prices.begin(), prices.end());
        
        int ans = 0;
        for(int i=0;i<n;i++){
            if(prices[i].first>k) break;
            
            int value = prices[i].first;
            int amount = prices[i].second;
            
            int x = k/value;
            //cout<<x<<endl;
            if(x>=amount){
                ans+=amount;
                k-=(value*amount);
            }
            else{
                ans+=x;
                k-=(value*x);
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, k;
	    cin >> n >> k;
	    int price[n];
	    for(int i = 0 ; i < n; i++){
	        cin >> price[i];
	    }
	    Solution ob;
	    int ans = ob.buyMaximumProducts(n, k, price);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends