# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def inorderTraversal(self, root):
        self.inorder_vals = []
        self.dfs(root)
        return self.inorder_vals
    
    def dfs(self, node):
        if not node:
            return
        
        self.dfs(node.left)
        self.inorder_vals.append(node.val)
        self.dfs(node.right)

        