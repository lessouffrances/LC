



class Solution 
{
    public:
    vector<int> preorderTraversal(TreeNode* root) 
    {
        if (!root) return {};   
        preorder.push_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
        
        return preorder;
    }
    private:
    vector<int> preorder;
};