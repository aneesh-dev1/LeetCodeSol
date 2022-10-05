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
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        while(root){
            if(!root ->left){
                inorder.push_back(root->val);
                root = root -> right;
            }
            else{
                TreeNode *rightMost = root->left;
                while(rightMost -> right != root && rightMost ->right ){
                    rightMost = rightMost ->right;
                }
                if(rightMost -> right != root){
                    rightMost ->right  = root;
                    root = root ->left;
                }
                else{
                    rightMost -> right = NULL;
                    inorder.push_back(root->val);
                    root = root ->right;
                }
            }
        }
        return inorder;
    }
};