# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution(object):
    def kthSmallest(self, root, k):
        if not root:
            return -1
        self.res = 0
        self.k = k
        self.dfs(root, self.k)
        return self.res
        
    def dfs(self, node, k):
        if not node:
            return -1
        
        self.dfs(node.left, k)
        self.k -= 1
        if self.k == 0:
            self.res = node.val
            return
            
        self.dfs(node.right, k)
        

        