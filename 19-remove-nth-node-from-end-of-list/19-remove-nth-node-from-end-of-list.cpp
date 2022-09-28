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
        return 1+ length(l1->next);
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head)
            return head;
        ListNode* list = head;
        ListNode* ans = list;
        int l = length(head);
        if(l == 1)
            return NULL;
        int start = l - n;
        int i = 0;
        if(start == 0)
            return list ->next;
        while(i<start-1){
            list = list ->next;
            i++;
        }
        if(list && list -> next)
            list -> next = list -> next -> next;
        return ans;
    }
};