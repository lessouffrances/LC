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
 
         if (root->val > key) {
             root->left = deleteNode(root->left, key);
         } else if (root->val < key) {
             root->right = deleteNode(root->right, key);
         } else {
             // find the node with key
             // case 1: node with only one child subtree
             if (!root->left) {
                 TreeNode* temp = root->right;
                 delete root;
                 return temp;
             }
             
             if (!root->right) {
                 TreeNode* temp = root->left;
                 delete root;
                 return temp;
             }
             
             // case 2: node with both child subtrees: swap with the successor of the root 
             TreeNode* successor = leftMost(root->right);
             root->val = successor->val;
             root->right = deleteNode(root->right, successor->val);
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