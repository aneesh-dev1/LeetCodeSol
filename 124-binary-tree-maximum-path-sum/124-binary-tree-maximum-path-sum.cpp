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
    int maxPathSum(TreeNode* root) {
       int sum =INT_MIN ;
       maxSum(root,sum);
       return sum;
    }
    int maxSum(TreeNode* root,int &sum){
        if(!root)
            return 0;
        int lSum = max(0,maxSum(root->left,sum));
        int rSum = max(0,maxSum(root->right,sum));
        sum = max(sum,root->val+lSum+rSum);
        return root->val+max(lSum,rSum);
    }
    
   
};