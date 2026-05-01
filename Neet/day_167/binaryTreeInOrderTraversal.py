class Solution(object):
    def inorderTraversal(self, root):
        if not root: 
            return []

        self.inorder = []
        self.dfs(root)
        return self.inorder

    def dfs(self, node):
        if not node:
            return []
        self.dfs(node.left)
        self.inorder.append(node.val)
        self.dfs(node.right)
 

        