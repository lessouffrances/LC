

// BST property
// split on root value


class Solution 
{
    public:
    TreeNode* deleteNode(TreeNode* root, int key) 
    {
        if (!root) return nullptr;
        if (root->val > key) {
            root->left = deleteNode(root->left, key);

        } else if (root->val < key) {
            root->right = deleteNode(root->right, key);

        } else {
            // leave
            if (!root->left && !root->right) {
                delete root;
                return nullptr;
            }

            // only left child
            if (!root->right) {
                TreeNode* tmp = root->left;
                delete root;
                return tmp;
            }
            // only right child
            if (!root->left) {
                TreeNode* tmp = root->right;
                delete root;
                return tmp;
            }

            // if has two children
            // has 2 ways
            // 1) find the predecessor, left subtree, rightMost node
            // 2) find the successor, right subtree, leftMost node
            // recursively delete on it
            TreeNode* successor = leftMost(root->right);
            root->val = successor->val;
            root->right = deleteNode(root->right, root->val);
        }
        return root;
    }

    private:
    TreeNode* leftMost(TreeNode* node)
    {
        while (node->left) {
            node = node->left;
        }
        return node;
    }
};