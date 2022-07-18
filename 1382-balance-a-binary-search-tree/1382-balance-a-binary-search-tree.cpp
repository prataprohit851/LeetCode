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
    vector<TreeNode*> IO;
    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        TreeNode* ptr = helper(0, IO.size()-1);
        return ptr;
    }
    
    TreeNode* helper(int i, int j){
        if(i > j) return NULL;
        int mid = i + (j-i)/2;
        IO[mid]->left = helper(i, mid-1);
        IO[mid]->right = helper(mid+1, j);
        return IO[mid];
    }
    
    void inorder(TreeNode* root){
        if(root == NULL) return;
        inorder(root->left);
        IO.push_back(root);
        inorder(root->right);
    }
};