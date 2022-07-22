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
    ListNode* partition(ListNode* head, int x) {
        ListNode* ptr = head;
        
        ListNode* small = new ListNode(INT_MAX);
        ListNode* large = new ListNode(INT_MAX);
        
        ListNode* one = small;
        ListNode* two = large;
        
        while(ptr){
            if(ptr->val < x){
                small->next = ptr;
                small = small->next;
            }
            else{
                large->next = ptr;
                large = large->next;
            }
            ptr = ptr->next;
        }
        small->next = two->next;
        large->next = NULL;
        return one->next;
    }
};