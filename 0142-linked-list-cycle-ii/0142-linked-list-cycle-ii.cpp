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
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) break;
        }

        if(!fast || !fast->next) return NULL;

        while(head != fast){
            cout<<"hes"<<endl;
            head = head->next;
            fast = fast->next;
        }

        return fast;
    }
};