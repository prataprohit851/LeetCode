# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def middleNode(self, head):
        
        q = head
        p = head
        
        while p and p.next:
            p = p.next.next
            q = q.next
            
        return q
        