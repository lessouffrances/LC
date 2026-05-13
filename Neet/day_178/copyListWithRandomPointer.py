
# Definition for a Node.
class Node:
    def __init__(self, x, next=None, random=None):
        self.val = int(x)
        self.next = next
        self.random = random

class Solution(object):
    def copyRandomList(self, head):
        if not head:
            return None
        
        old_to_new = {}
        curr = head
        while curr:
            node = Node(curr.val)
            old_to_new[curr] = node
            curr = curr.next

        curr = head
        while curr:
            new_curr = old_to_new[curr]
            new_curr.next = old_to_new[curr.next] if curr.next else None
            new_curr.random = old_to_new[curr.random] if curr.random else None
            curr = curr.next

        return old_to_new[head]