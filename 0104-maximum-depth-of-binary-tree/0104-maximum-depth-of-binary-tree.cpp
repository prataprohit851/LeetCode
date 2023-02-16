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
    int maxDepth(TreeNode* root) {
        if(root) dfs(root, 1);
        return ans;
    }
    void dfs(TreeNode* root, int len){
        if(root->left == NULL && root->right == NULL){
            ans = max(ans, len);
        }
        if(root->left) dfs(root->left, len+1);
        if(root->right) dfs(root->right, len+1);
    }
};



// BFS
// class Solution {
// public:
//     int maxDepth(TreeNode* root) {
//         queue<TreeNode*> q;
//         if(root) q.push(root);
//         int ans = 0;
//         while(!q.empty()){
//             ans++;
//             int sz = q.size();
//             while(sz--){
//                 TreeNode* n = q.front();
//                 q.pop();
//                 if(n->left) q.push(n->left);
//                 if(n->right) q.push(n->right);
//             }
//         }
//         return ans;
//     }
// };