# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        cur = head
        pre = None
        nex = None
        while cur != None:
            nex = cur.next
            cur.next = pre
            pre = cur
            cur = nex
        return pre
        