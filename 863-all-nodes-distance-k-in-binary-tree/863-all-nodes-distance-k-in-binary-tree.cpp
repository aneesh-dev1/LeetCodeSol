/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    void parentPointer(TreeNode *root,map<TreeNode*,TreeNode*> &parent){
        if(!root) return;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode * node = q.front();
            q.pop();
            if(node->left){
                parent[node->left] = node;
                q.push(node->left);
            }
            if(node->right){
                parent[node->right] = node;
                q.push(node->right);
            }
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*,TreeNode*> parent;
        parentPointer(root,parent);
        map<TreeNode*,bool> vis;
        vis[target] = true;
        int dist = 0;
        queue<TreeNode*> q;
        q.push(target);
        while(!q.empty()){
            int size = q.size();
            if(dist++ == k) break;
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left && !vis[node->left]){
                    q.push(node->left);
                    vis[node->left] =true;
                }
                if(node->right && !vis[node->right]){
                    q.push(node->right);
                    vis[node->right] =true;
                }
                if(parent[node] && !vis[parent[node]]){
                    q.push(parent[node]);
                    vis[parent[node]] =true;
                }
            }
        }
        vector<int> ans;
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            ans.push_back(it->val);
        }
        return ans;
    }
};