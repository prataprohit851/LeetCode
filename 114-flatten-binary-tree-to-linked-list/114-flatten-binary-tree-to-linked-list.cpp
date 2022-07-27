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
        preTraversal(root);
        TreeNode* ptr = NULL;
        while(st.size()){
            st.top()->right = ptr;
            st.top()->left = NULL;
            ptr = st.top();
            st.pop();
        }
    }
    stack<TreeNode*> st;
    void preTraversal(TreeNode* root){
        if(root == NULL) return;
        st.push(root);
        if(root->left) preTraversal(root->left);
        if(root->right) preTraversal(root->right);
    }
};