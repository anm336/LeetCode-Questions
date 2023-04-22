//{ Driver Code Starts
#include<bits/stdc++.h>
 
using namespace std; 


bool findPair(int arr[], int size, int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int l,n;
        cin>>l>>n;
        int arr[l];
        for(int i=0;i<l;i++)
            cin>>arr[i];
        if(findPair(arr, l, n))
            cout<<1<<endl;
        else cout<<"-1"<<endl;
    }
    
  
    return 0;
}
// } Driver Code Ends


bool findPair(int arr[], int size, int n){
    //code
    unordered_map<int, int> mapping;
    for(int i=0;i<size;i++){
        mapping[arr[i]]++;
    }
    int arr2[size];
    for(int i=0;i<size;i++){
        arr2[i] = arr[i];
    }
    for(int i=0;i<size;i++){
        arr[i] = arr[i] - n;
    }
    bool chck = false;
    for(int i=0;i<size;i++){
        if((arr2[i]!=arr[i] && mapping[arr[i]]>0) || (arr2[i]==arr[i] && mapping[arr[i]]>1)){
            return true;
            break;
        }
    }
    return chck;
}