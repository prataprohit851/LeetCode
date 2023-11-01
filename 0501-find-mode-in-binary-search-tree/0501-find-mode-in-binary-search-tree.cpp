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

    vector<int> modes;
    int currentNum = 0;
    int currentCount = 0;
    int maxCount = 0;

    vector<int> findMode(TreeNode* root) {
        helper(root);
        return modes;
    }

    


    void helper(TreeNode* root){
        if(!root) return;
        helper(root->left);

        if(root->val == currentNum){
            currentCount++;
        }
        else{
            currentCount = 1;
        }

        if(currentCount == maxCount){
            modes.push_back(root->val);
        }
        else if(currentCount > maxCount){
            maxCount = currentCount;
            modes = {root->val};
        }
        currentNum = root->val;

        helper(root->right);
    }
};

