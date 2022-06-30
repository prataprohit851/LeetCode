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
        Node* ptr = root;
        while(ptr->left!= NULL){
            Node* qtr = ptr;
            while(qtr != NULL){
                qtr->left->next = qtr->right;
                if(qtr->next == NULL) qtr->right->next = NULL;
                else qtr->right->next = qtr->next->left;
                qtr = qtr->next;
            }
            ptr = ptr->left;
        }
        return root;
    }
};