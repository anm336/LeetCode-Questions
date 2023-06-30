//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
		
	int isDivisible(string s){
	    //complete the function here
	    //Observation based if abs(setBits at even pos.n - setBits at odd pos.n)%3 == 0 return true;
	    int n = s.size();
	    int ec=0, oc=0;
	    for(int i=0;i<n;i++){
	        if(s[i]=='1'){
	            if(i%2 == 0) ec++;
	            else oc++;
	        }
	    }
	    
	    return abs(ec-oc)%3==0;
	}

};

//{ Driver Code Starts.
int main(){
    
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isDivisible(s) << endl;
    }
return 0;
}


// } Driver Code Ends