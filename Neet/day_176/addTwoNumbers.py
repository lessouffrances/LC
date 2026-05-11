# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        if not l1:
            return l2
        if not l2:
            return l1
        
        dummy = ListNode()
        curr = dummy

        carry = 0
        while l1 or l2 or carry:
            summation = carry

            if l1:
                summation += l1.val
                l1 = l1.next
            if l2:
                summation += l2.val
                l2 = l2.next
            
            digit = summation % 10
            carry = summation // 10
            node = ListNode(digit)
            curr.next = node
            curr = curr.next
        
        return dummy.next





        