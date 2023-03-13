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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        if(lists.size()==1) return lists[0];
        map<int,int> mapping;
        for(int i=0;i<lists.size();i++){
            ListNode* temp = lists[i];
            while(temp!=NULL){
                mapping[temp-> val]++;
                temp = temp-> next;
            }
        }
        ListNode* ans = new ListNode(1);
        ListNode* ans2 = ans;
        for(auto [x,y] : mapping){
            for(int i=0;i<y;i++){
                ListNode* temp = new ListNode(x);
                ans-> next = temp;
                ans = ans-> next;
            }
        }
        return ans2-> next;
    }
};