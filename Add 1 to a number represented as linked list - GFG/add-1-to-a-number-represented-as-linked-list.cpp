//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    Node* reverse(Node* prev,Node* temp){
        if(temp==NULL) return prev;
        
        Node* next = temp-> next;
        temp-> next = prev;
        
        return reverse(temp, next);
    }
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        Node* temp = head;
        Node* node = reverse(NULL, temp);
        Node* ans = node;
        int carry = 1;
        while(node-> next!=NULL && carry==1){
            if(node-> data == 9){
                node-> data = 0;
            }
            else{
                node-> data += 1;
                carry = 0;
            }
            node = node-> next;
        }
        if(carry == 1){
            if(node-> data == 9){
                Node* newNode = new Node(1);
                node-> data = 0;
                node-> next = newNode;
            }
            else node-> data += 1;
        }
        return reverse(NULL, ans);
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends