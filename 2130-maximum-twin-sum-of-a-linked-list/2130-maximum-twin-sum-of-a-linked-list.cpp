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
        int n = 0;
        ListNode* tempa = head;
        
        while(tempa!=NULL){
            n++;
            tempa = tempa -> next;
        }
        
        vector<int> sums;
        int x = 0;
        ListNode* temp = head;
        while(x<n/2){
            sums.push_back(temp-> val);
            temp = temp-> next;
            x++;
        }
        
        int y = n/2-1;
        
        while(x<n){
            sums[y] += temp-> val;
            temp = temp-> next;
            x++;
            y--;
        }
        
        return *max_element(sums.begin(), sums.end());
    }
};