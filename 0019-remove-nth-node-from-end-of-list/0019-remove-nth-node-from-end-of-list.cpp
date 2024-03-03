/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int s=0;
        ListNode* temp = head;
        while(temp != NULL){
            s++;
            temp = temp-> next;
        }
        if(s==1) return NULL;
        int x = s-n;
        if(x==0) return head-> next;
        ListNode* temp1 = head;
        while(x>1){
            temp1 = temp1-> next;
            x--;
        }
        ListNode* temp2 = temp1-> next -> next;
        temp1-> next = temp2;
        return head;
    }
};