from collections import deque
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

        q = deque()
        q.append( [root, 0, 0] ) # [node, row, col]
        vals_by_col = {}

        while q:
            node, row, col = q.popleft()
            if col not in vals_by_col:
                vals_by_col[col] = []
            vals_by_col[col].append( [row, node.val] )

            if node.left: 
                q.append( [node.left, row+1, col-1] )
            if node.right:
                q.append( [node.right, row+1, col+1] )

        res = []
        for col in sorted(vals_by_col.keys()):
            row_vals = vals_by_col[col]
            row_vals.sort()
            res.append( [val for _, val in row_vals] )
        return res
        