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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = new TreeNode(preorder[0]);
        for(int i = 1; i < preorder.size(); i++)
            helper(root, preorder[i]);
        return root;
    }
    
    void helper(TreeNode* root, int num){
        if(num < root->val){
            if(!root->left){
                root->left = new TreeNode(num);
                return;
            }
            helper(root->left, num);
        }
        else{
            if(!root->right){
                root->right = new TreeNode(num);
                return;
            }
            helper(root->right, num);
        }
    }
};