//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
class Solution
{
    public:
    /*You are required to complete this method*/
    int findK(int a[MAX][MAX],int n,int m,int k)
    {
 		// Your code goes here.
 		int si=0, sj=0, ei=n-1, ej=m-1;
 		int cnt=0;
 		while(si<=ei && sj<=ej){
 		    for(int q=sj; q<=ej; q++){
 		        cnt++;
 		        if(cnt==k) return a[si][q];
 		    }
 		    si+=1;
 		    for(int q=si; q<=ei; q++){
 		        cnt++;
 		        if(cnt==k) return a[q][ej];
 		    }
 		    ej-=1;
 		    for(int q=ej; q>=sj; q--){
 		        cnt++;
 		        if(cnt==k) return a[ei][q];
 		    }
 		    ei-=1;
 		    for(int q=ei; q>=si; q--){
 		        cnt++;
 		        if(cnt==k) return a[q][sj];
 		    }
 		    sj+=1;
 		}
 		
 		return -1;
    }
};





//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        Solution ob;
        cout<<ob.findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends