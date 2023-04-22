//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
vector<int> find(int arr[], int n , int x )
{
    int fi = -1;
    int li = -1;
    int chck = 0;
    for(int i=0;i<n;i++){
        if(chck==0){
            if(arr[i]==x){
                fi = i;
                li = i;
                chck = 1;
            }
        }
        else{
            if(arr[i]==x) li = i;
        }
    }
    vector<int> ans;
    ans.push_back(fi);
    ans.push_back(li);
    return ans;
    // code here
}

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends