class Solution 
{
    public:
    int rangeSumBST(TreeNode* root, int low, int high) 
    {
        dfs(root, low, high);
        return sum;
    }
    private:
    int sum = 0;
    void dfs(TreeNode* node, int low, int high)
    {
        if (!node) return;

        if (node->val >= low && node->val <= high) {
            sum += node->val;
        }
        if (node->val > low) {
            dfs(node->left, low, high);
        }
        if (node->val < high) {
            dfs(node->right, low, high);
        }
    } 
};