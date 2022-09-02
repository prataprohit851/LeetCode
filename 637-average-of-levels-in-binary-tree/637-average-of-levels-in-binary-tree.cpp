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
    vector<double> ans;
    stack<TreeNode*> st;
    vector<double> averageOfLevels(TreeNode* root) {
        st.push(root);
        if(st.size()) helper();
        return ans;
    }
    void helper(){
        long val = 0, sz = st.size();
        stack<TreeNode*> temp;
        while(st.size()){
            TreeNode* top = st.top();
            st.pop();
            if(top->left) temp.push(top->left);
            if(top->right) temp.push(top->right);
            val += top->val;
        }
        st = temp;
        ans.push_back((double)val/sz);
        if(st.size()) helper();
    }
};