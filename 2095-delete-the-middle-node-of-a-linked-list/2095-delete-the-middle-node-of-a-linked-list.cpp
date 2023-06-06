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
    ListNode* deleteMiddle(ListNode* head) {
        if(head-> next == NULL) return NULL;
        ListNode* slow = head;
        ListNode* fast = head-> next;
        ListNode* prev;
        
        while(fast && fast-> next){
            prev = slow;
            slow = slow-> next;
            fast = fast-> next-> next;
        }
        
        if(fast != NULL){
            ListNode* temp = slow-> next;
            slow-> next = temp-> next;
        }
        else{
            prev-> next = slow-> next;
        }
        return head;
    }
};