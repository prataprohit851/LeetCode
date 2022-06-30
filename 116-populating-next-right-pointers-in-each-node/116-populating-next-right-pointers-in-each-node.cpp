/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    
    Node* connect(Node* root) {
        if(root == NULL) return NULL;
        queue<Node*> st;
        st.push(root);
        
        helper(st);
        return root;
    }
    void helper(queue<Node*> st){
        if(st.size() == 0) return;
        queue<Node*> temp;
        Node* prev = NULL;
        while(st.size() != 0){
            
            prev = st.front();
            st.pop();
            
            if(st.size() != 0) prev->next = st.front();
            else prev->next = NULL;
            
            if(prev->left) temp.push(prev->left);
            if(prev->right) temp.push(prev->right);
        }
        helper(temp);
    }
};