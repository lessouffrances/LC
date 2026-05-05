# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def binaryTreePaths(self, root):
        if not root: 
            return []

        self.res = []
        curr_path = ""
        self.dfs(root, curr_path)
        return self.res
    
    def dfs(self, node, curr_path):
        if not node:
            return
        
        curr_path += str(node.val)
        if not node.left and not node.right:
            self.res.append(curr_path)
            return self.res
        
        curr_path += "->"
        self.dfs(node.left, curr_path)
        self.dfs(node.right, curr_path)
        