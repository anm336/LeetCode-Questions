//{ Driver Code Starts
// Initial Template for C++



#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int pageFaults(int N, int C, int pages[]){
        // code here
        int pf = 0;
        
        unordered_set<int> s;
        unordered_map<int,int> memory;
        
        for(int i=0;i<N;i++){
            if(s.size()<C){
                if (s.find(pages[i])==s.end()){
                    s.insert(pages[i]);
                    pf++;
                    
                }
                memory[pages[i]] = i;
            }
            else{
                if (s.find(pages[i])==s.end()){
                    pf++;
                    int index = INT_MAX, val;
                    for(auto x: s){
                        if(memory[x]<index){
                            index = memory[x];
                            val=x;
                        }
                    }
                    s.erase(val);
                    s.insert(pages[i]);
                }
                memory[pages[i]] = i;
            }
        }
        
        return pf;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, C;
        cin>>N;
        int pages[N];
        for(int i = 0;i < N;i++)
            cin>>pages[i];
        cin>>C;
        
        Solution ob;
        cout<<ob.pageFaults(N, C, pages)<<"\n";
    }
    return 0;
}
// } Driver Code Ends