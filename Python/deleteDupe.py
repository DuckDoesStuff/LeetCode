class ListNode:
     def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def deleteDuplicates(self, head: ListNode) ->ListNode:
        if head == None: return None
        
        res = ListNode(-1)
        dummy = res
        prev = head
        nxt = head.next
        
        while nxt:
            if prev.val != nxt.val:
                dummy.next = prev
                dummy = dummy.next
            prev = prev.next
            nxt = nxt.next
        dummy.next = prev
            
        return res.next