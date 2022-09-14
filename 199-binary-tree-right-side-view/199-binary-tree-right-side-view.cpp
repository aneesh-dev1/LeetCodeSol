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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        rightMaker(root,res,0);
        return res;
    }
    vector<int> rightMaker(TreeNode* root,vector<int> &res,int level){
        if(!root)
            return res;
        if(res.size() == level){
            res.push_back(root->val);
        }
        rightMaker(root->right,res,level+1);
        rightMaker(root->left,res,level+1);
        return res;
    }
    
  
    
};