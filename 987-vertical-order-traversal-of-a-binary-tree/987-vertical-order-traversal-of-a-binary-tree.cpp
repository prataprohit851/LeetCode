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
    vector<vector<int>> coords;
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        coords.push_back({root->val, 0, 0});
        helper(root, 0, 0);
        vector<vector<int>> ans;
        sort(coords.begin(), coords.end(), hemloHelper);
        
        vector<int> temp;
        temp.push_back({coords[0][0]});
        
        for(int i = 1; i < coords.size(); i++){
            if(coords[i][2] != coords[i-1][2] && temp.size()){
                ans.push_back(temp);
                temp.clear();
            }
            temp.push_back(coords[i][0]);
        }
        ans.push_back(temp);
        
        return ans;
    }
    void helper(TreeNode* root, int n, int m){
        if(root == NULL) return;
            
        if(root->left){
            coords.push_back({root->left->val, n+1, m-1});
            helper(root->left, n+1, m-1);
        }
        if(root->right){
            coords.push_back({root->right->val, n+1, m+1});
            helper(root->right, n+1, m+1);
        }
    }
    static bool hemloHelper(vector<int> a, vector<int> b){
        if(a[2] == b[2]) {
            if(a[1] == b[1]) return a[0] < b[0];
            else return a[1] < b[1];
        }
        else return a[2] < b[2];
    }
};