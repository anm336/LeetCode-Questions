//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
vector<int> find(int arr[], int n , int x )
{
    int fi = -1;
    int li = -1;
    
    int i = 0;
    int j = n;
    while(i<j){
        int mid = ((j-i)/2) + i;
        if(arr[mid]==x){
            fi = mid;
            j = mid;
        }
        else if(arr[mid]>x){
            j = mid;
        }
        else{
            i = mid+1;
        }
    }
    
    i=0;
    j=n;
    while(i<j){
        int mid = ((j-i)/2) + i;
        if(arr[mid]==x){
            li = mid;
            i = mid+1;
        }
        else if(arr[mid]>x){
            j = mid;
        }
        else{
            i = mid+1;
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