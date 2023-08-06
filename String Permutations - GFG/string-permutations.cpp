//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    void findPerm(int i, string &S, int n, vector<string> &ans){
        if(i==n){
            ans.push_back(S);
            return;
        }
        
        for(int j=i; j<n; j++){
            swap(S[i], S[j]);
            findPerm(i+1, S, n, ans);
            swap(S[i], S[j]);
        }
    }
    
    vector<string> permutation(string S)
    {
        //Your code here
        vector<string> ans;
        int n = S.size();
        
        findPerm(0, S, n, ans);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends