//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int minFlips (string s);
int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;

        cout << minFlips (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends


int minFlips (string S)
{
    int cnt1 = 0, cnt2 = 0;
    for(int i=0;i<S.size();i++){
        if(i%2==0 && S[i]=='1'){
            cnt1++;
        }
        if(i%2!=0 && S[i]=='0'){
            cnt1++;
        }
    }
    for(int i=0;i<S.size();i++){
        if(i%2!=0 && S[i]=='1'){
            cnt2++;
        }
        if(i%2==0 && S[i]=='0'){
            cnt2++;
        }
    }
    return min(cnt1, cnt2);
    // your code here
}