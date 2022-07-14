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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preInd = 0;
        return helper(preorder, inorder, 0, inorder.size()-1, preInd);
    }
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int start, int end, int& preInd){
        if(start > end) return NULL;
        TreeNode* root = new TreeNode(preorder[preInd]);
        int i = indFinder(inorder, preorder[preInd]);
        preInd++;
        root->left = helper(preorder, inorder, start, i-1, preInd);
        root->right = helper(preorder, inorder, i+1, end, preInd);
        return root;
    }
    int indFinder(vector<int>& inorder, int element){
        for(int i = 0; i < inorder.size(); i++){
            if(element == inorder[i]) return i;
        }
        return -1;
    }
};