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
        unordered_set<int> s;
        for(auto it:pre)
            s.insert(it);
        for(int i =0;i<pre.size();i++){
            if(s.find(k-pre[i]) != s.end() && k-pre[i] != pre[i])
                return true;
        }
        return false;
    }
};