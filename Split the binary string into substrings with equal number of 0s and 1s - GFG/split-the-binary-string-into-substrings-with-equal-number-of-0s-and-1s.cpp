//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int maxSubStr(string str){
        //Write your code here
        int cnt = 0;
        int zc = 0;
        int oc = 0;
        int n = str.size();
        for(int i=0;i<n;i++){
            if(str[i] == '0') zc++;
            else oc++;
            //cout<<zc<<" "<<oc<<endl;
            
            if(zc == oc){
                cnt++;
                zc = 0;
                oc = 0;
            }
        }
        
        if(zc == 0 && oc == 0 && cnt != 0) return cnt;
        return -1;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin >> str;
	    Solution ob;
	    int ans = ob.maxSubStr(str);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends