class Node:
    def __init__(self, key):
        self.val = key
        self.left = None
        self.right = None

def insert(root, key):
    if root is None:
        return Node(key)
    if root.val == key:
        return root
    if root.val < key:
        root.right = insert(root.right, key)
    else:
        root.left = insert(root.left, key)
    return root

def inorder(root):
    if root:
        inorder(root.left)
        print(root.val, end=' ')
        inorder(root.right)

def search(root, key):
    if root is None or root.val == key:
        return root
    if root.val < key:
        return search(root.right, key)
    return search(root.left, key)

def getSuccessor(curr):
    curr = curr.right
    while curr is not None and curr.left is not None:
        curr = curr.left
    return curr

def delete(root, key):
    if root is None:
        return root
    
    if root.val > key:
        root.left = delete(root.left, key)
    elif root.val < key:
        root.right = delete(root.right, key)
    else:
        if root.left is None:
            return root.right
        if root.right is None:
            return root.left
        succ = getSuccessor(root)
        root.val = succ.val
        root.right = delete(root.right, succ.val)
        
    return root




