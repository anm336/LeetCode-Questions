//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
  public:
    //Function to check whether the list is palindrome.
    Node* reverse(Node* prev, Node* temp){
        if(temp==NULL) return prev;
        Node* next = temp-> next;
        temp-> next = prev;
        
        return reverse(temp, next);
    }
    
    bool isPalindrome(Node *head)
    {
        //Your code here
        if(head==NULL || head-> next==NULL) return head;
        if(head-> next-> next == NULL){
            if(head-> data == head-> next-> data) return true;
            else return false;
        }
        
        int n = 0;
        Node* temp = head;
        while(temp != NULL){
            n++;
            temp = temp-> next;
        }
        
        int m;
        if(n%2 == 0) m = n/2;
        else m = n/2 + 1;
        
        Node* temp2 = head;
        int x = m;
        while(x--){
            temp2 = temp2-> next;
        }
        
        Node* temp3 = reverse(NULL, temp2);
        
        if(n%2!=0) m--;
        while(m--){
            if(head-> data != temp3-> data){
                return false;
            }
            if(head!=NULL) head = head-> next;
            if(temp3!=NULL) temp3 = temp3-> next;
        }
        
        return true;
    }
};



//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends