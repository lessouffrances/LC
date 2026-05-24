
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
            return head

        curr = head
        stack = []

        while curr:
            if curr.child:
                if curr.next:
                    stack.append(curr.next)

                    # reconnect
                    curr.next = curr.child
                    curr.child.prev = curr
                    curr.child = None
            
            if not curr:
                saved = stack[-1]
                stack.pop()
                curr.next = saved
                saved.prev = curr

            curr = curr.next
        return head

        