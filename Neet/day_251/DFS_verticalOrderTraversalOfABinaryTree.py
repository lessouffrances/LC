# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def verticalTraversal(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: List[List[int]]
        """

        if not root: return []
        self.vals_by_col = {} # col : [ [row, val] ]
        self.dfs(root, 0, 0)

        res = []
        for col in sorted(self.vals_by_col.keys()):
            row_vals = self.vals_by_col[col]
            row_vals.sort()
            res.append( [ val for _, val in row_vals] )
        return res
    
    def dfs(self, node, row, col):
        """
        :type node: TreeNode
        :rtype: none
        """

        if not node: return
        if col not in self.vals_by_col: 
            self.vals_by_col[col] = []
        self.vals_by_col[col].append( [row, node.val] )

        if node.left: self.dfs(node.left, row+1, col-1)
        if node.right: self.dfs(node.right, row+1, col+1)
