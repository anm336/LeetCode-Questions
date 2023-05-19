//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        Node* ans = new Node(0);
        Node* temp = ans;
        
        Node* temp1 = first;
        Node* prev1 = NULL;
        while(temp1!=NULL){
            Node* next = temp1-> next; 
            temp1-> next = prev1;
            prev1 = temp1;
            temp1 = next;
        }
        Node* firsty = prev1;
        
        Node* temp2 = second;
        Node* prev2 = NULL;
        while(temp2!=NULL){
            Node* next = temp2-> next; 
            temp2-> next = prev2;
            prev2 = temp2;
            temp2 = next;
        }
        Node* secondy = prev2;
        
        int carry = 0;
        
        while(firsty!= NULL && secondy!= NULL){
            int val = firsty-> data + secondy-> data + carry;
            Node* node = new Node(val%10);
            temp-> next = node;
            temp = temp-> next;
            carry = val/10;
            firsty= firsty-> next;
            secondy = secondy-> next;
        }
        while(firsty!=NULL){
            int val = firsty-> data + carry;
            Node* node = new Node(val%10);
            temp-> next = node;
            temp = temp-> next;
            carry = val/10;
            firsty= firsty-> next;
        }
        while(secondy!=NULL){
            int val = secondy-> data + carry;
            Node* node = new Node(val%10);
            temp-> next = node;
            temp = temp-> next;
            carry = val/10;
            secondy = secondy-> next;
        }
        
        while(carry!=0){
            int val = carry%10;
            Node* node = new Node(val);
            temp-> next = node;
            temp = temp-> next;
            carry/=10;
        }
        
        Node* temp3 = ans-> next;
        Node* prev3 = NULL;
        while(temp3!=NULL){
            Node* next = temp3-> next; 
            temp3-> next = prev3;
            prev3 = temp3;
            temp3 = next;
        }
        Node* fans = prev3;
        return fans;
        // code here
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends