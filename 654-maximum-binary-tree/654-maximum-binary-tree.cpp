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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return helper(NULL, nums, 0, nums.size()-1);
    }
    
    TreeNode* helper(TreeNode* root, vector<int>& nums, int sind, int eind){
        if(sind > eind) return NULL;
        int maxEle = INT_MIN;
        int maxInd = -1;

        for(int i = sind; i <= eind; i++){
            if(nums[i] > maxEle){
                maxEle = nums[i];
                maxInd = i;
            }
        }
        
        TreeNode* ptr = new TreeNode(maxEle);
        
        ptr->left = helper(ptr, nums, sind, maxInd-1);
        ptr->right = helper(ptr, nums, maxInd+1, eind);
        
        return ptr;
    }
};