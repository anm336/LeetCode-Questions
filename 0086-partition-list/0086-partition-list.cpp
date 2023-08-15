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
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL) return head;
        vector<int> fhalf, shalf;
        
        while(head){
            if(head-> val < x) fhalf.push_back(head-> val);
            else shalf.push_back(head-> val);
            head = head-> next;
        }
        
        if(fhalf.size()==0){
            ListNode* ans = new ListNode(shalf[0]);
            ListNode* temp = ans;
            
            for(int i=1;i<shalf.size();i++){
                ListNode* node = new ListNode(shalf[i]);
                temp-> next = node;
                temp = temp-> next;
            }
            
            return ans;
        }
        
        ListNode* ans = new ListNode(fhalf[0]);
        ListNode* temp = ans;

        for(int i=1;i<fhalf.size();i++){
            ListNode* node = new ListNode(fhalf[i]);
            temp-> next = node;
            temp = temp-> next;
        }
        for(int i=0;i<shalf.size();i++){
            ListNode* node = new ListNode(shalf[i]);
            temp-> next = node;
            temp = temp-> next;
        }

        return ans;
    }
};