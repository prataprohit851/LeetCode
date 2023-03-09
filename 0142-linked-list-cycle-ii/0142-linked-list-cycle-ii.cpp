/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL) return NULL;
        set<ListNode*> st;
        st.insert(head);
        while(st.find(head->next) == st.end()){
            st.insert(head->next);
            head = head->next;
            if(head == NULL) return NULL;
        }
        return head->next;
    }
};