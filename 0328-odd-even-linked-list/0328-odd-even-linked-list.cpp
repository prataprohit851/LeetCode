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
    ListNode* oddEvenList(ListNode* head) {

        ListNode* oddStartingNode = new ListNode(0);
        ListNode* evenStartingNode = new ListNode(0);

        ListNode* oddCurrNode = oddStartingNode;
        ListNode* evenCurrNode = evenStartingNode;

        bool isOdd = true;

        while(head){
            if(isOdd){
                oddCurrNode->next = head;
                oddCurrNode = oddCurrNode->next;
                isOdd = false;
            }
            else{
                evenCurrNode->next = head;
                evenCurrNode = evenCurrNode->next;
                isOdd = true;
            }
            head = head->next;
        }

        evenCurrNode->next = NULL;
        oddCurrNode->next = evenStartingNode->next;
        
        return oddStartingNode->next;
    }
};