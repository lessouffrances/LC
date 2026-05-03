# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def getIntersectionNode(self, headA, headB):
        if not headA or not headB:
            return None

        while headA:
            pB = ListNode()
            while pB:
                if pB == headA:
                    return pB
                pB = pB.next
            headA = headA.next
        return None

        