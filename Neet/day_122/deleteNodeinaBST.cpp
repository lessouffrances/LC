
// use the binary search to find the node with key

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

            // if the node is a leaf
            if (!root->left && !root->right) {
                delete root;
                return nullptr;
            }
            // if only has one child
            // save the child first
            // simply delete the root, and return the left/right child 
            if (!root->right) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            if (!root->left) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }

            // if has two children
            // 2 ways: 
            // 1) find the predecessor: left subtree, rightMost node
            // 2) find the successor: right subtree, leftMost node
            // recurse delete on left/right subtree
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