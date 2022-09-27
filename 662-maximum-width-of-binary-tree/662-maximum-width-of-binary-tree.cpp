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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        int width = 0;
        while(!q.empty()){
            int size = q.size();
            int currMin = q.front().second;
            int first,last;
            for(int i=0;i<size;i++){
                TreeNode* node = q.front().first;
                int newIndex = q.front().second - currMin;
                q.pop();
                if(i == 0){
                    first = newIndex;
                }
                if(i == size-1){
                    last = newIndex;
                }
                if(node->left)
                    q.push({node->left,(long long)newIndex*2+1});
                if(node->right)
                    q.push({node->right,(long long)newIndex*2+2});
            }
            width = max(width,last-first+1);
        }
        return width;
    }
};