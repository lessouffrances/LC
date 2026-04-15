# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def inorderSuccessor(self, root: TreeNode, p: TreeNode) -> Optional[TreeNode]:
        if not root:
            return None

        self.prev = None
        return self.dfs(root, p)
        
    def dfs(self, node: TreeNode, p: TreeNode) -> TreeNode:
        if not node:
            return None
        
        left = self.dfs(node.left, p)
        if left:
            return left
        
        if self.prev == p:
            return node
        self.prev = node

        return self.dfs(node.right, p)

        
