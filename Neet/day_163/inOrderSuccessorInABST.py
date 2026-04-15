# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def inorderSuccessor(self, root, p):
        if not root: 
            return None
        self.prev = None
        return self.dfs(root, p)

    def dfs(self, node, p):
        if not node: 
            return None
        left = self.dfs(node.left, p)
        if left:
            return left
        prev = node
        return self.dfs(node.right, p)

        