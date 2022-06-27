/**
 * Example:
 * var li = ListNode(5)
 * var v = li.`val`
 * Definition for singly-linked list.
 * class ListNode(var `val`: Int) {
 *     var next: ListNode? = null
 * }
 */
class Solution {
    fun removeNthFromEnd(head: ListNode?, n: Int): ListNode? {
        var p: ListNode? = head
        var q: ListNode? = head
        for (i in 1..n){
            p = p?.next
        }
        if(p == null) return head?.next
        while(p?.next != null){
            p = p?.next
            q = q?.next
        }
        q?.next = q?.next?.next
        return head
    }
}