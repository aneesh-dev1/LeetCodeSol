/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        node->val = node->next->val;
        node->next = node->next->next;
    }
};