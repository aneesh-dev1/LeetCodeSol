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
       int sum = INT_MIN;
        maximumPathSum(root,sum);
        return sum;
    }
    int maximumPathSum(TreeNode* root,int & sum){
        if(!root)
            return 0;
        int leftSum = max(0,maximumPathSum(root->left,sum));
        int rightSum = max(0,maximumPathSum(root->right,sum));
        sum = max(sum,root->val+leftSum+rightSum);
        return root->val+max(leftSum,rightSum);
    }
    
    
   
};