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
    
    ListNode* merge(ListNode* head,ListNode* head2){
        if(!head)
            return head2;
        if(!head2)
            return head;
        ListNode* ans = NULL;
        if(head -> val<head2->val){
            ans = head;
            head = head -> next;
        }
        else{
            ans = head2;
            head2 = head2 -> next;
        }
        ListNode* result = ans;
        while(head && head2){
            if(head->val<head2->val){
                ans -> next = head;
                head = head ->next;
            }
            else{
                ans -> next = head2;
                head2 = head2 -> next;
            }
            ans = ans->next;
        }
        if(head){
            ans->next = head;
        }
        if(head2)
            ans->next = head2;
        return result;
    }
    
    
    ListNode* middle(ListNode* node){
        ListNode* slow = node;
        ListNode* fast = node;
        while(fast -> next && fast->next ->next){
            slow = slow -> next;
            fast = fast -> next ->next;
        }
        return slow;
    }
    
    
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode* mid = middle(head);
        ListNode* head2 = mid->next;
        mid->next = NULL;
        ListNode* res = merge(sortList(head),sortList(head2));
        return res;
    }
};