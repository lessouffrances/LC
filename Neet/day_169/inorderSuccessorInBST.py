# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def inorderSuccessor(self, root, p):
        if not root:
            return root
        self.prev = None
        return self.dfs(root, p)

    def dfs(self, node, p):
        if not node:
            return node
        left = self.dfs(node.left, p)
        if left: 
            return left
        if self.prev == p:
            return node
        self.prev = node

        return self.dfs(node.right, p)   