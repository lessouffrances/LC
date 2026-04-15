from platform import node
from collections import deque

# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next

class Solution:
    def connect(self, root: 'Optional[Node]') -> 'Optional[Node]':
        if not root:
            return None

        q = deque()
        q.append(root)

        while q:
            size = len(q)
            level_nodes = []
            for _ in range(size):
                node = q.popleft()
                level_nodes.append(node)
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
            
            # assign right pointer
            for i in range(size-1):
                level_nodes[i].next = level_nodes[i+1]

        return root
