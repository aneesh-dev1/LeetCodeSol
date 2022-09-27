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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
       vector<vector<int>> res;
        if(!root)
            return res;
        bool flag = true;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> sub;
            for(int i =0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
                sub.push_back(node->val);
            }
            if(flag)
                res.push_back(sub);
            else{
                reverse(sub.begin(),sub.end());
                res.push_back(sub);
            }
            flag = !flag;
            }
            return res;
    }
};