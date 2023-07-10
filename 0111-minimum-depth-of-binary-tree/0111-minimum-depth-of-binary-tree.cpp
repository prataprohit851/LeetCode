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
    int ans = INT_MAX;
    int minDepth(TreeNode* root) {
        helper(root, 1);
        return ans;
    }
    void helper(TreeNode* root, int l){
        if(!root){
            ans = 0;
            return;
        }
        if(!root->left && !root->right) ans = min(ans, l);
        if(root->left) helper(root->left, l+1);
        if(root->right) helper(root->right, l+1);
    }
};