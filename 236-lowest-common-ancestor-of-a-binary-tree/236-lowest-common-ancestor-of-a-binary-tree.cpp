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
public:
    TreeNode* lowestCommonAncestor(TreeNode* r, TreeNode* p, TreeNode* q) {
        if(r == NULL || r == p || r == q) return r;
        TreeNode* left = lowestCommonAncestor(r->left, p, q);
        TreeNode* right = lowestCommonAncestor(r->right, p, q);
        
        if(left == NULL) return right;
        else if(right == NULL) return left;
        else return r;
    }
};