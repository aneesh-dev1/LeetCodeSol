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
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = INT_MIN;
        dia_cal(root,diameter);
        return diameter;
    }
    int dia_cal(TreeNode* root,int &dia){
        if(!root) return 0;
        int lh = dia_cal(root->left,dia);
        int rh = dia_cal(root->right,dia);
        dia = max(dia,lh+rh);
        return 1+max(lh,rh);
    }
};