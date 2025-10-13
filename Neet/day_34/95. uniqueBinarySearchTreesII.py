# Definition for a binary tree node.
from collections import deque

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class BinarySearchTree:
    def __init__(self):
        self.root = None
    
    def insert(self, data):
        self.root = self._insert_recursive(self.root, data)
    
    def _insert_recursive(self, treenode, data):
        if treenode == None:
            return TreeNode(data)
        if data > treenode.val:
            treenode.right = self._insert_recursive(treenode.right, data)
        elif data < treenode.val:
            treenode.left = self._insert_recursive(treenode.left, data)
        return treenode

class Solution:
    def generateTrees(self, n):

        def bfs_traversal(root):
            if not root:
                return []
    
            result = []
            queue = deque([root])
    
            while queue:
                node = queue.popleft()
                result.append(node.val)
        
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
    
            return result

        nodes = [ num for num in range(1, n+1) ]
        res = []

        for i, selected_root in enumerate(nodes):
            left_subtree = nodes[: i]
            right_subtree = nodes[i+1 :]
            remaining_tree = left_subtree+right_subtree

            tree = BinarySearchTree()
            tree.insert(selected_root)

            for node in remaining_tree:
                tree.insert(node)
            
            print(bfs_traversal(tree.root))
            
def main():
    solution = Solution()
    solution.generateTrees(3)
main()