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
    void flatten(TreeNode* root) {
       // if(!root)
       //     return ;
       //  flatten(root->right);
       //  flatten(root->left);
       //  root->right = prev;
       //  root->left = NULL;
       //  prev = root;
        // if(!root)
        //     return ;
        // stack<TreeNode*> st;
        // st.push(root);
        // while(!st.empty()){
        //     TreeNode* temp = st.top();
        //     st.pop();
        //     if(temp -> right) 
        //         st.push(temp->right);
        //     if(temp -> left) 
        //         st.push(temp -> left);
        //     if(!st.empty()){
        //         temp ->right = st.top();
        //     }
        //     temp -> left = NULL;
        // }
        TreeNode* curr = root;
        while(curr){
            if(curr -> left){
                TreeNode* leftTree = curr -> left;
                while(leftTree -> right)
                    leftTree = leftTree -> right;
                leftTree -> right = curr ->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr = curr ->right;
        }
    }
};