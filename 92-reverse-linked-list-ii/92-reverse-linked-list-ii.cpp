//  Definition for singly-linked list.
//  struct ListNode {
//      int val;
//      ListNode *next;
//      ListNode() : val(0), next(nullptr) {}
//      ListNode(int x) : val(x), next(nullptr) {}
//      ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* node = new ListNode(INT_MAX, head);
        head = node;
        
        ListNode* ptr = head->next;
        ListNode* qtr = head;
        
        for(int i = 1; i < left; i++){
            qtr = ptr;
            ptr = ptr->next;
        }

        ListNode* two = ptr;
        ListNode* prev = NULL;
        ListNode* temp = NULL;
        
        for(int i = left; i < right; i++){
            temp = ptr->next;
            ptr->next = prev;
            prev = ptr;
            ptr = temp;
        }
        if(temp != NULL){
            temp = temp->next;
            ptr->next = prev;
            qtr->next = ptr;
            two->next = temp;
        }

        return head->next;
    }
};