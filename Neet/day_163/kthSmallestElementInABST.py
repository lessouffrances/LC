# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        if not root: 
            return -1

        self.k = k
        return self.dfs(root)

    def dfs(self, node: TreeNode) -> int:
        if not node: 
            return -1

        left = self.dfs(node.left)
        if left != -1:
            return left
        
        self.k -= 1
        if self.k == 0:
            return node.val
        
        right = self.dfs(node.right)
        if right != -1:
            return right
        return -1



        