# Definition for a Node.
class Node(object):
    def __init__(self, val, prev, next, child):
        self.val = val
        self.prev = prev
        self.next = next
        self.child = child


class Solution(object):
    def flatten(self, head):
        if not head:
            return None

        curr = head
        stack = []

        while curr:
            if curr.child:
                if curr.next:
                    # save the next for later
                    stack.append(curr.next)
                
                # reconnect curr with child
                curr.next = curr.child
                curr.child = None
                curr.next.prev = curr
            
            if not curr.next and stack:
                saved = stack[-1]
                stack.pop()

                curr.next = saved
                saved.prev = curr
            curr = curr.next
            
        return head
        