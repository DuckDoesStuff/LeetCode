class ListNode:
     def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def addTwoNumbers(l1: ListNode, l2: ListNode) -> ListNode:
    dummy = ListNode()
    curr = dummy

    carry = 0
    while (l1 or l2 or carry):
        v1 = l1.val if l1 else 0
        v2 = l2.val if l2 else 0

        sum = v1 + v2 + carry
        curr.next = ListNode(sum%10)
        carry = sum // 10

        curr = curr.next
        if l1: 
            l1 = l1.next
        if l2: 
            l2 = l2.next

    return dummy.next


