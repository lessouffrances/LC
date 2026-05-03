class Solution(object):
    def oddEvenList(self, head):
        if not head:
            return head
        
        even_curr = head.next
        odd_curr = head
        even_head = even_curr

        while even_curr and even_curr.next:
            odd_curr.next = even_curr.next
            odd_curr = odd_curr.next
            even_curr.next = odd_curr.next
            even_curr = even_curr.next
        
        odd_curr.next = even_head
        return head