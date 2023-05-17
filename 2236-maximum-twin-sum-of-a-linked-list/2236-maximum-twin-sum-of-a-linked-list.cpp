/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        stack<int> st;
        int lengthOfLL = 1;
        ListNode *a = head;
        ListNode *b = head->next;
        
        while(b->next != NULL){
            a = a->next;
            b = b->next->next;
            lengthOfLL++;
        }
        
        a = a->next;
        b = head;
        
        while(a != NULL){
            st.push(a->val);
            a = a->next;
        }
        
        int maxVal = 0;
        
        while(st.size()){
            if((b->val + st.top()) > maxVal){
                maxVal = b->val + st.top();
            }
            st.pop();
            b = b->next;
        }
        return maxVal;
    }
};