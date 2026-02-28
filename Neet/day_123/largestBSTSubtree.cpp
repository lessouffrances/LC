


struct Info
{
    bool isBST;
    int minVal;
    int maxVal;
    int subtreeSum;
};
class Solution 
{
    public:
    int largestBSTSubtree(TreeNode* root) 
    {
        if (!root) return 0;
        dfs(root);
        return maxSum;
    }

    private:
    // postorder
    // contribution margin: 
    int maxSum = 0;
    Info dfs(TreeNode* node)
    {
        if (!node) return {true, INT_MAX, INT_MIN, 0};

        Info leftInfo = dfs(node->left);
        Info rightInfo = dfs(node->right);

        // local info
        // if BST:
        bool isBST = (node->val > leftInfo.maxVal 
            && node->val < rightInfo.minVal) 
            && leftInfo.isBST && rightInfo.isBST;

        if (!isBST) return {false, 0, 0, 0};

        // minVal & maxVal
        int minVal = node->left ? leftInfo.minVal : node->val;
        int maxVal = node->right ? rightInfo.maxVal : node->val;

        // size
        int subtreeSum = 1 + leftInfo.subtreeSum + rightInfo.subtreeSum;
        maxSum = max(maxSum, subtreeSum);
        return {true, minVal, maxVal, subtreeSum};
    }
};