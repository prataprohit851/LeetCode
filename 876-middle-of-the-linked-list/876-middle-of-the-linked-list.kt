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
    fun middleNode(head: ListNode?): ListNode? {
        var p: ListNode? = head
        var q: ListNode? = head
        while (p != null && p?.next != null){
            p = p?.next?.next
            q = q?.next
        }
        return q
    }
}