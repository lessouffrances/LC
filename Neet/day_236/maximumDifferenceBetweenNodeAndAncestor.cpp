class Solution 
{
    public:
    int maxAncestorDiff(TreeNode* root) 
    {
        dfs(root, root->val, root->val);
        return maxDiff;
    }
    private:
    int maxDiff = INT_MIN;
    // maxDiff = abs(a.val - b.val)
    void dfs(TreeNode* node, int ancestorMax, int ancestorMin)
    {
        if (!node) return;
        maxDiff = max( {maxDiff, abs(ancestorMax-node->val), abs(ancestorMin-node->val)} );

        ancestorMax = max(node->val, ancestorMax);
        ancestorMin = min(node->val, ancestorMin);

        dfs(node->left, ancestorMax, ancestorMin);
        dfs(node->right, ancestorMax, ancestorMin);
    }
}; 