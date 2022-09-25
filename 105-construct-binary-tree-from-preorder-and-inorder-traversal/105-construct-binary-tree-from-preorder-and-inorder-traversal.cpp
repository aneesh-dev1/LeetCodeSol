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
    TreeNode* builder(vector<int> &pre,int preStart,int preEnd,vector<int> &in,int inStart,int inEnd,map<int,int>& mapper){
        if(preStart>preEnd || inStart>inEnd)
            return NULL;
        TreeNode* root = new TreeNode(pre[preStart]);
        int finder = mapper[pre[preStart]];
        int div = finder - inStart;
        root -> left = builder(pre,preStart+1,preStart+div,in,inStart,finder,mapper);
        root -> right = builder(pre,preStart+div+1,preEnd,in,finder+1,inEnd,mapper);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> mapper;
        for(int i=0;i<inorder.size();i++)
            mapper[inorder[i]] = i;
        TreeNode* root = builder(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mapper);
        return root;
    }
};