//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    int findindex(int start, int end, int in[], int x){
        for(int i=start;i<=end;i++){
            if(in[i] == x) return i;
        }
        return -1;
    }
    
    Node* func(int in[], int pre[], int n, int &index, int start, int end){
        if(start>end || index>=n) return NULL;
        
        int element = pre[index++];
        Node* root = new Node(element);
        int pos = findindex(start, end, in, element);
        
        root-> left = func(in, pre, n, index, start, pos-1);
        root-> right = func(in, pre, n, index, pos+1, end);
        
        return root;
    }
    
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        int index = 0;
        Node* ans = func(in, pre, n, index, 0, n-1);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends