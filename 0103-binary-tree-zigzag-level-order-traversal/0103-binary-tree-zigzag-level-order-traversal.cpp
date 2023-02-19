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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        int flag = 0;
        if(root) q.push(root);
        while(!q.empty()){
            int sz = q.size();
            vector<int> temp;
            while(sz--){
                TreeNode* node = q.front();
                temp.push_back(node->val);
                q.pop();
                if(node->left != NULL) q.push(node->left);
                if(node->right != NULL) q.push(node->right);
            }
            if(flag){
                reverse(temp.begin(), temp.end());
                flag = 0;
            }
            else flag = 1;
            ans.push_back(temp);
        }
        return ans;
    }
};