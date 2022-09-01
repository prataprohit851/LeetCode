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
    int goodNodes(TreeNode* root) {
        vector<int> v;
        helper(root, v);
        return ans;
    }
    void helper(TreeNode* root, vector<int> &v){
        if(root == NULL) return;
        v.push_back(root->val);
        helper(root->left, v);
        if(root->val >= *max_element(v.begin(), v.end())) ans++;
        helper(root->right, v);
        v.pop_back();
    }
};