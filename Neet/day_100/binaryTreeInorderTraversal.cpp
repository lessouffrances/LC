


class Solution 
{
    public:
    vector<int> inorderTraversal(TreeNode* root) 
    {
        if (!root) return {};

        if (root->left) {
            inorderTraversal(root->left);
        }
        
        res.push_back(root->val);
        if (root->right) {
            inorderTraversal(root->right);
        }
        
        return res;
    }
    private:
    vector<int> res;
};