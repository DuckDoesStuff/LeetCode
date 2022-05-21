class ListNode:
     def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def mergeTwoLists(list1: ListNode, list2: ListNode) -> ListNode:
    result = ListNode(-1)
    dummy = result

    while(list1 and list2):
        if(list1.val <= list2.val):
            while(list1 and list1.val <= list2.val):
                dummy.next = list1
                list1 = list1.next
                dummy = dummy.next
            dummy.next = list2
        else:
            while(list2 and list2.val < list1.val):
                dummy.next = list2
                list2 = list2.next
                dummy = dummy.next
            dummy.next = list1

    if(not list1):
            dummy.next = list2
    if(not list2):
            dummy.next = list1

    return result.next