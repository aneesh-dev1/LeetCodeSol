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
    void parentPointer(TreeNode* root,map<TreeNode*,TreeNode*> &parent){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
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
        queue<TreeNode*> q;
        q.push(target);
        int dis = 0;
        while(!q.empty()){
            int size = q.size();
            if(dis++ == k)
                break;
            for(int i=0;i<size;i++){
                TreeNode*node = q.front();
                q.pop();
                if(node->left && !vis[node->left]){
                    vis[node->left] = true;
                    q.push(node->left);
                }
                if(node->right && !vis[node->right]){
                    vis[node->right] = true;
                    q.push(node->right);
                }
                if(parent[node] && !vis[parent[node]]){
                    vis[parent[node]] = true;
                    q.push(parent[node]);
                }
            }
        }
        vector<int> ans;
        while(!q.empty()){
            TreeNode* a = q.front();
            q.pop();
            ans.push_back(a->val);
        }
        return ans;
    }
};