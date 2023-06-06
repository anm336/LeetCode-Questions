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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head-> next == NULL || head-> next-> next == NULL) return head;
        ListNode* secondpart = head-> next;
        
        ListNode* ans = head;
        while(head && head-> next){
            ListNode* temp = head-> next;
            head-> next = head-> next-> next;
            if(head-> next) temp-> next = head-> next-> next;
            else temp-> next = NULL;
            if(head-> next) head = head-> next;
        }
        head-> next = secondpart;
        
        return ans;
    }
};