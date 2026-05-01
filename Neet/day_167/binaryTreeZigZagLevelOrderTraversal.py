from collections import deque

class Solution(object):
    def zigzagLevelOrder(self, root):
        if not root: 
            return []

        # init a queue
        q = deque()
        # push to root to the q
        q.append(root)
        level = 0
        res = []

        while q:
            size = len(q)
            curr_level = []
            for _ in range(size):
                # q front
                node = q[0]
                q.popleft()
                curr_level.append(node.val)

                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
            
            if level % 2 != 0:
                curr_level = curr_level[::-1]
            res.append(curr_level)
            level+=1
            
        return res


                

        