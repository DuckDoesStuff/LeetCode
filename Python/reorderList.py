class ListNode:
     def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def reorderList(self, head: ListNode) -> None:
        slow = head
        fast = slow.next

        while fast:
            slow = slow.next
            fast = fast.next
            if fast: fast = fast.next
            else: break
        
        curr = slow
        reversed = None

        while curr:
            nxt = curr.next
            curr.next = reversed

            reversed = curr
            curr = nxt
        
        while reversed.next and head.next:
            headNext = head.next
            revNext = reversed.next

            head.next = reversed
            reversed.next = headNext

            reversed = revNext
            head = headNext

