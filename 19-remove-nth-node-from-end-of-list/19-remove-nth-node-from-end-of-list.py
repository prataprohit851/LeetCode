# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def removeNthFromEnd(self, head, n):
        p = head
        q = head
        for i in range(n):
            p = p.next
        if(p == None): return head.next
        while(p.next != None):
            p = p.next
            q = q.next
        q.next = q.next.next
        return head