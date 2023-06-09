//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X)
    {
        //Your Code Here
        for(int i=0;i<n;i++){
            int x = X-A[i];
            unordered_map<int, int> mapping;
            
            for(int j=i;j<n;j++){
                if(j!=i){
                    int y = x-A[j];
                    if(mapping.find(y) != mapping.end()){
                        return true;
                    }
                    
                    mapping[A[j]]++;
                }
            }
        }
        
        return false;
    }

};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,X;
		cin>>n>>X;
		int i,A[n];
		for(i=0;i<n;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}

// } Driver Code Ends