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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode *ptr = new ListNode();
        ListNode *temp = ptr;
        
        while(list1 || list2){
            
            if(list2 == NULL){
                ptr->next = list1;
                break;
            }
            
            else if(list1 == NULL){
                ptr->next = list2;
                break;
            }
            
            if(list1->val < list2->val){
                ptr->next = new ListNode(list1->val);
                list1 = list1->next;
                ptr = ptr->next;
            }

            else if(list1->val > list2->val){
                ptr->next = new ListNode(list2->val);
                list2 = list2->next;
                ptr = ptr->next;
            }

            else if(list1->val == list2->val){
                ptr->next = new ListNode(list2->val);
                list2 = list2->next;
                ptr = ptr->next;
                ptr->next = new ListNode(list1->val);
                list1 = list1->next;
                ptr = ptr->next;
            }
        }
        return temp->next;
    }
};