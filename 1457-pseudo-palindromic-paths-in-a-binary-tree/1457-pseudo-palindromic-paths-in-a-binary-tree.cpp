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
    
    int pseudoPalindromicPaths (TreeNode* root) {
        
        vector<int> dp(10, 0);
        int ans = 0;
        
        helper(root, dp, ans);
        return ans;
    }
    
    void helper(TreeNode* root, vector<int> &dp, int &ans){
        if(!root) return;
        
        dp[root->val-1] += 1;
        helper(root->left, dp, ans);
        helper(root->right, dp, ans);
        if(root->left == NULL && root->right == NULL){
            int odd = 0;
            for(int i = 0; i < 10; i++){
                if(dp[i] % 2 != 0) odd++;
            }
            if(odd < 1 || odd == 1) ans++;
        }
        dp[root->val-1] -= 1;
    }
};