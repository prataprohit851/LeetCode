/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        map<Node*, Node*> list;

        Node* originalHead = head;

        while(head){
            list[head] = new Node(head->val); 
            head = head->next;
        }

        head = originalHead;

        while(head){
            list[head]->next = list[head->next];
            list[head]->random = list[head->random];
            head = head->next; 
        }
        return list[originalHead];
    }
};