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
    int sumOfLeftLeaves(TreeNode* root, TreeNode* parent = NULL) {
        if(root == NULL) return 0;
        int sum = 0;
        if(parent == NULL){
            sum += sumOfLeftLeaves(root->left, root);
            sum += sumOfLeftLeaves(root->right, root);
            return sum;
        }
        if(root->left == NULL && root->right == NULL && root == parent->left){
            sum += root->val;
        }
        if(root->right) sum += sumOfLeftLeaves(root->right, root);
        if(root->left) sum += sumOfLeftLeaves(root->left, root);
        return sum;
    }
};