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
    bool isPalindrome(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = new ListNode(0, head);

        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }

        if(fast) fast = slow->next->next;
        else fast = slow->next;

        slow->next = NULL;

        ListNode* prev = NULL;

        while(fast){
            ListNode* temp = fast->next;
            fast->next = prev;
            prev = fast;
            fast = temp;
        }

        fast = prev;
        slow = head;
        
        while(fast && slow){
            if(fast->val != slow->val) return false;
            fast = fast->next;
            slow = slow->next;
        }

        return true;
    }
};