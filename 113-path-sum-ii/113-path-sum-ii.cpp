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
    void pathCalc(TreeNode* root,int targetSum,int sum,vector<vector<int>> & ans,vector<int>& path){
        if(!root)
            return;
        path.push_back(root->val);
        sum+=root->val;
        if(targetSum == sum && !root->left && !root->right){
            ans.push_back(path);
            sum =0;
        }
        else{
            pathCalc(root->left,targetSum,sum,ans,path);
            pathCalc(root->right,targetSum,sum,ans,path);
        }
        path.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;
        int sum = 0;
        pathCalc(root,targetSum,sum,ans,path);
        return ans;
    }
};