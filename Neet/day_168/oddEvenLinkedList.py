class Solution(object):
    def oddEvenList(self, head):
        if not head:
            return head

        evenCurr = head.next
        oddCurr = head
        evenHead = evenCurr

        while evenCurr and evenCurr.next:
            oddCurr.next = evenCurr.next
            oddCurr = oddCurr.next
            evenCurr.next = oddCurr.next
            evenCurr = evenCurr.next

        oddCurr.next = evenHead
        return head