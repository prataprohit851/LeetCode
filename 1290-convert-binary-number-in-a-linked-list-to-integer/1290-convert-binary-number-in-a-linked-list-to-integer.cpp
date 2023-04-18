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
    int getDecimalValue(ListNode* head) {
        ListNode* h = head;
        int i = 0;
        while(h){
            i++;
            h = h->next;
        }
        i--;
        int ans = 0;
        h = head;
        while(h){
            ans += (pow(2,i--)*h->val);
            h = h->next;
        }
        cout<<endl;
        return ans;
    }
};