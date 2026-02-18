struct Info
{
    bool isBST;
    int minVal;
    int maxVal;
    int size;
};

class Solution 
{
    public:
    int largestBSTSubtree(TreeNode* root) 
    {
        dfs(root);
        return maxSize;
    }
    private:
    //postorder
    int maxSize = 0;
    Info dfs(TreeNode* node)
    {
        if (!node) return {true, INT_MAX, INT_MIN, 0};

        Info left = dfs(node->left);
        Info right = dfs(node->right);

        if (left.isBST && right.isBST 
        && node->val > left.maxVal && node->val < right.minVal) {
            int currSize = 1 + left.size + right.size;
            int maxVal = (right.size == 0) ? node->val : right.maxVal;
            int minVal = (left.size == 0) ? node->val : left.minVal;
            maxSize = max(maxSize, currSize);
            return { true, minVal, maxVal, currSize };
        }

        return { false, 0, 0, 0 };
    }
};