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
    ListNode* swapNodes(ListNode* head, int k) {
        if(!head)
            return head;
        int l = length(head);
        int start = k;
        int end = l-k; 
        ListNode * slow = head;
        ListNode* fast = head;
        int i = 0;
        while(i<start-1){
            slow = slow -> next;
            i++;
        }
        i = 0;
        while(i<end){
            fast = fast ->next;
            i++;
        }
        swap(slow -> val, fast -> val);
        return head;
    }
};