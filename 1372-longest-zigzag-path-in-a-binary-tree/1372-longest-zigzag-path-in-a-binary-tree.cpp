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
    int ans = 0;
    int longestZigZag(TreeNode* root) {
        dfs(root, true, 0);
        dfs(root, false, 0);
        return ans;
    }
    void dfs(TreeNode* root, bool isLeft, int i){
        if(root == NULL) return;
        ans = max(ans, i);
        if(isLeft){
            // return max(1+dfs(root->right, false), dfs(root->left, true));
            dfs(root->right, false, i+1);
            dfs(root->left, true, 1);
        }
        else{
            // return max(1+dfs(root->left, true), dfs(root->right, false));
            dfs(root->left, true, i+1);
            dfs(root->right, false, 1);
        }
    }
};