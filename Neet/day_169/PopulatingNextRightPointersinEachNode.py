from collections import deque
# Definition for a Node.
class Node(object):
    def __init__(self, val=0, left=None, right=None, next=None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next

class Solution(object):
    def connect(self, root):
        if not root: 
            return root

        q = deque()
        q.append(root)

        while q:
            size = len(q)
            curr_level = []
            for _ in range(size):
                node = q[0]
                q.popleft()
                curr_level.append(node)

                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
            
            for i in range(size-1):
                curr_level[i].next = curr_level[i+1]
        return root
            
                



        