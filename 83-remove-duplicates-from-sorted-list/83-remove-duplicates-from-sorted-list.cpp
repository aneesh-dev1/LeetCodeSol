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
        ListNode* l1 = head;
        ListNode* l2 = new ListNode();
        ListNode* dummy = l2;
        set<int> s;
        while(l1){
            s.insert(l1->val);
            l1 = l1->next;
        }
        for(auto it:s){
            ListNode* node = new ListNode(it);
            dummy->next = node;
            dummy = dummy ->next;
        }
        return l2 ->next ;
    }
};