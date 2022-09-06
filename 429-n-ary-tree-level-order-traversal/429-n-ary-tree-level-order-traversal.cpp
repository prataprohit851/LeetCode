/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root) return {};
        vector<vector<int>> ans;
        queue<Node*> st;
        st.push(root);
        
        while(st.size()){
            vector<int> level;
            int n = st.size();
            for(int i = 0; i < n; i++){
                Node *ptr = st.front();
                st.pop();
                
                for(auto childrens : ptr->children){
                    st.push(childrens);
                }
                level.push_back(ptr->val);
            }
            ans.push_back(level);
        }
        return ans;
    }
};