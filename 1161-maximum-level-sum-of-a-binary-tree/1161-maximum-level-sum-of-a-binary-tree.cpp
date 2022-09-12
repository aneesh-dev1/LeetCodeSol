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
    int maxLevelSum(TreeNode* root) {
        if(!root)
            return 0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,1});
        int level = 1;
        int maxSum=root->val;
        while(!q.empty()){
            int size = q.size();
            int currSum = 0 ;
            int temp;
            for(int i=0;i<size;i++){
                auto it = q.front();
                TreeNode* node = it.first;
                int l = it.second;
                q.pop();
                if(node->left){
                    q.push({node->left,l+1});
                }
                if(node->right){
                    q.push({node->right,l+1});
                }
                currSum+=node->val;
                temp = l;
            }
            if(currSum>maxSum){
                    level = temp;
                    maxSum = currSum;
            } 
        }
        return level;
    }
};