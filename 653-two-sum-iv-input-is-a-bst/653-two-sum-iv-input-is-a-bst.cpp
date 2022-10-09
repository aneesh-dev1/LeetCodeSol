/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    void preOrder(TreeNode* root,vector<int> &pre){
        if(!root)
            return;
        pre.push_back(root->val);
        preOrder(root->left,pre);
        preOrder(root->right,pre);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> pre;
        preOrder(root,pre);
        int left = 0,right = pre.size()-1;
        sort(pre.begin(),pre.end());
        while(left<right){
            int sum = pre[left]+pre[right];
            if(sum == k)
                return true;
            else if(sum<k)
                left++;
            else
                right--;
        }
        return false;
    }
};