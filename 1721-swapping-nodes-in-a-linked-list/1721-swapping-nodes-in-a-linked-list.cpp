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
    ListNode* swapNodes(ListNode* head, int k) {
        int n=0;
        ListNode* temp = head;
        while(temp-> next!=NULL){
            n++;
            temp = temp-> next;
        }
        int k1 = k-1;
        int k2 = n-k+1;
        ListNode* temp1 = head;
        ListNode* temp2 = head;
        while(k1>0){
            temp1 = temp1-> next;
            k1--;
        }
        while(k2>0){
            temp2 = temp2-> next;
            k2--;
        }
        int val1,val2;
        val1 = temp1-> val;
        val2 = temp2-> val;
        temp1-> val = val2;
        temp2-> val = val1;
        return head;
    }
};