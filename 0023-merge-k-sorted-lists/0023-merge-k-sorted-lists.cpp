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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = NULL;
        ListNode* ans = new ListNode(0);
        ListNode* temp = ans;
        int ind = -1;
        do{
            head = NULL;
            ind = -1;
            for(int i = 0; i < lists.size(); i++){
                if(lists[i] != NULL){
                    if(ind == -1 || head->val > lists[i]->val){
                        head = lists[i];
                        ind = i;
                    }
                }
            }
            temp->next = head;
            temp = temp->next;
            if(ind != -1) lists[ind] = lists[ind]->next;
        } while(head);
        return ans->next;
    }
};