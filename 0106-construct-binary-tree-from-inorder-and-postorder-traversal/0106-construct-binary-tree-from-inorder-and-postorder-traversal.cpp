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
    map<int, int> mp;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i = 0; i < inorder.size(); i++) mp[inorder[i]] = i;
        return helper(inorder, postorder, 0, inorder.size()-1);
    }
    TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int m, int n){
        if(m > n) return NULL;
        int num = postorder.back();
        TreeNode* node = new TreeNode(num);
        postorder.pop_back();
        node->right = helper(inorder, postorder, mp[num]+1, n);
        node->left = helper(inorder, postorder, m, mp[num]-1);
        return node;
    }
};