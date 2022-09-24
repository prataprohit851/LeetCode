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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> q;
        if(root){
            helper(root, q, 0, targetSum);
        }
        return ans;
    }
    
    vector<vector<int>> ans;
    
    void helper(TreeNode* root, vector<int> &q, int sum, int &targetSum){
        sum += root->val;
        q.push_back(root->val);
        if(root->left == NULL && root->right == NULL && sum == targetSum)
            ans.push_back(q);
        if(root->left) helper(root->left, q, sum, targetSum);
        if(root->right) helper(root->right, q, sum, targetSum);
        q.pop_back();
        sum -= root->val;
    }
};