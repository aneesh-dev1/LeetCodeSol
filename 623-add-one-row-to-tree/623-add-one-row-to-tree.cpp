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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(!root)
            return NULL;
        if(depth == 1){
            TreeNode* node = new TreeNode(val);
            TreeNode* newNode = root;
            root = node;
            root->left = newNode;
        }
        queue<TreeNode*> q;
        q.push(root);
        int level = 1;
        while(!q.empty()){
            level++;
            int size = q.size();
            if(level == depth)
                break;
            while(size--){
                TreeNode* node = q.front();
                q.pop();
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
        }
        int size = q.size();
        while(size--){
            TreeNode*node = q.front();
            q.pop();
            TreeNode* leftNode = node->left , *rightNode = node->right;
            node->left = new TreeNode(val);
            node->left->left = leftNode;
            node->right = new TreeNode(val);
            node->right->right = rightNode;
        }
        return root;
    }
};