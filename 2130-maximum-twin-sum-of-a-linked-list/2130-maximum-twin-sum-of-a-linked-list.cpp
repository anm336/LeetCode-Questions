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
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast!=NULL && fast-> next!=NULL){
            slow = slow-> next;
            fast = fast-> next-> next;
        }
        
        //Reverse 2nd half;
        ListNode* next;
        ListNode* prev = NULL;
        while(slow != NULL){
            next = slow-> next;
            slow-> next = prev;
            prev = slow;
            slow = next;
        }
        
        int maxsum = 0;
        ListNode* start = head;
        while(prev!= NULL){
            maxsum = max(maxsum, head-> val + prev-> val);
            head = head-> next;
            prev = prev-> next;
        }
        
        return maxsum;
    }
};