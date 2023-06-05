//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        //1) Create Node to parent mapping
        // 3 nodes can be burnt by a node, its left, right, parent.
        //2) find target Node
        //Find while making parent map itself
        //3) Burn in min time
        //Do level order traversal, check for the neighbours of all the nodes in a queue at a time(all of them)
        //If neighbours not burnt add in queue and mark visited
        //If any is burnt add to time also, else not required to add time
        //Do until queue becomes empty
        
        Node* node = NULL;
        map<Node*, Node*> mapping;
        
        queue<Node*> q;
        q.push(root);
        mapping[root] = NULL;
        while(!q.empty()){
            Node* front = q.front();
            q.pop();
            
            if(front-> data == target) node = front;
            
            if(front-> left){
                mapping[front-> left] = front;
                q.push(front-> left);
            }
            if(front-> right){
                mapping[front-> right] = front;
                q.push(front-> right);
            }
        }
        
        int time = 0;
        map<Node*, bool> vis;
        queue<Node*> q2;
        
        q2.push(node);
        vis[node] = true;
        
        while(!q2.empty()){
            int size = q2.size();
            bool flag = false;
            
            while(size--){
            Node* front = q2.front();
            q2.pop();
            if(front-> left && !vis[front-> left]){
                q2.push(front-> left);
                vis[front-> left] = true;
                flag = true;
            }
            if(front-> right && !vis[front-> right]){
                q2.push(front-> right);
                vis[front-> right] = true;
                flag = true;
            }
            if(mapping[front] && !vis[mapping[front]]){
                q2.push(mapping[front]);
                vis[mapping[front]] = true;
                flag = true;
            }
            }
            
            if(flag) time++;
        }
        
        return time;
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends