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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> vec;
        while(head){
            vec.push_back(head->val);
            head = head->next;
        }
        return helper(vec, 0, vec.size()-1);
    }
    TreeNode* helper(vector<int> vec, int s, int e){
        if(s > e) return NULL;
        int mid = s - (s - e)/2;
        TreeNode* node = new TreeNode(vec[mid]);
        node->left = helper(vec, s, mid-1);
        node->right = helper(vec, mid+1, e);
        return node;
    }
};