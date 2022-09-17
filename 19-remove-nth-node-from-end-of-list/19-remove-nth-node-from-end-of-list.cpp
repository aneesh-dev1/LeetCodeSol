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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head;
        ListNode* a = head;
        int size = 0;
        while(slow != NULL){
            size++;
            slow = slow->next;
        }
        int start = size - n;
        int i = 0;
        while(i<start-1){
            head = head->next;
            i++;
        }
        if(start == 0){
            
            return head->next;
    }
        head->next = head->next->next;
        return a;
    }
};