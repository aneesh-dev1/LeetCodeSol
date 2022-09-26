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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)
            return head;
        map<int,int> mp;
        ListNode* l1 = head;
        ListNode* l2 = head;
        ListNode* res = new ListNode();
        ListNode* dummy = res;
        while(l1){
            mp[l1->val]++;
            l1= l1->next;
        }
        while(l2){
            if(mp[l2->val] == 1){
                ListNode* node = new ListNode(l2->val);
                dummy ->next = node;
                dummy = dummy->next;
            }
            l2 = l2->next;
        }
        return res -> next;
    }
};