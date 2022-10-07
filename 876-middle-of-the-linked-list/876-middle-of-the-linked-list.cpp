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
private:
    int length(ListNode* h){
        if(!h)
            return 0;
        return 1+length(h->next);
    }
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        int size = length(head);
        while(fast->next && fast->next->next){
            slow = slow ->next;
            fast = fast -> next ->next;
        }
        return size&1?slow : slow->next;
    }
};