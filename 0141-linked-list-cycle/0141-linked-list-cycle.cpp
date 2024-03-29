/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head) return false;
        
        ListNode* slow = head;
        ListNode* fast = head-> next;
        
        while(fast && fast-> next && slow!=fast){
            //if(!slow-> next) return false;
            slow = slow-> next;
            fast = fast-> next-> next;
        }
        
        return slow==fast;
    }
};