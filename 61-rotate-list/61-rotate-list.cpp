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
    int length(ListNode* l1){
        if(!l1)
            return 0;
        return 1+length(l1->next);
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next)
            return head;
        int start = length(head) - k%length(head);
        ListNode* slow = head;
        ListNode* fast = head;
        int i=0;
        while(i<abs(start -1)){
            i++;
            slow = slow ->next;
        }
        while(fast->next != NULL){
            fast = fast ->next;
        }
        fast ->next = head;
       
        ListNode* ans = slow->next;
        slow->next = NULL;
        return ans;
    }
};