//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        stack<char> stck;
        stck.push('X');
        bool ans = true;
        for(int i=0;i<x.size();i++){
            if(x[i]=='(' || x[i]=='{' || x[i]=='['){
                stck.push(x[i]);
            }
            else{
                char a = stck.top();
                char b = x[i];
                if(b==')'){
                    if(a=='('){
                        stck.pop();
                    }
                    else{
                        ans=false;
                        break;
                    }
                }
                else if(b=='}'){
                    if(a=='{'){
                        stck.pop();
                    }
                    else{
                        ans=false;
                        break;
                    }
                }
                else{
                    if(a=='['){
                        stck.pop();
                    }
                    else{
                        ans=false;
                        break;
                    }
                }
            }
        }
        if(stck.top()!='X') ans = false;
        return ans;
        // Your code here
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends