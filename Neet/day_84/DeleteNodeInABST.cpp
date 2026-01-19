/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 class Solution 
 {
     public:
     // post-order
     TreeNode* deleteNode(TreeNode* root, int key)
     {
        if (!root) return nullptr;

        // binary search to find the node with key
        if (root->val < key) {
            root->right = deleteNode(root->right, key);
        } else if (root->val > key) {
            root->left = deleteNode(root->left, key);
        } else {
            // case 1: if is a leaf
            if (root->left == nullptr && root->right == nullptr) {
                delete root;
                return nullptr;
            } else if (root->right == nullptr && root->left != nullptr) {
                // case 2: if only has left child 
                return root->left;
            } else if (root->right != nullptr) {
                TreeNode* successor = leftMost(root->right);
                root->val = successor->val;
                root->right = deleteNode(root->right, successor->val);
            }
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