# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution(object):
    def buildTree(self, preorder, inorder):
        if not preorder or not inorder:
            return None
        
        root = TreeNode(preorder[0])
        split_val = root.val
        split_val_idx = self.findSplitIdxInorder(split_val, inorder)

        # preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
        inorder_left = inorder[ : split_val_idx]
        inorder_right = inorder[ split_val_idx+1 : ]
        preorder_left = preorder[ 1 : split_val_idx+1 ]
        preorder_right = preorder[ split_val_idx+1 : ]

        root.left = self.buildTree(preorder_left, inorder_left)
        root.right = self.buildTree(preorder_right, inorder_right)

        return root

    def findSplitIdxInorder(self, split_val, inorder):
        for i in range(len(inorder)):
            if inorder[i] == split_val:
                return i
        return -1


        