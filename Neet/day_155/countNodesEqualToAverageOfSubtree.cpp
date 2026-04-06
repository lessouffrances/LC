


struct Info
{
    int count = 0; // num of nodes that equal to the avg of the subtree
    int numOfNodes = 0;
    int sum = 0;   
};


class Solution 
{
    public:
    int averageOfSubtree(TreeNode* root) 
    {
        if (!root) return 0;
        Info info = dfs(root);
        return info.count;
    }

    private:
    // postorder
    Info dfs(TreeNode* node)
    {
        if (!node) return { 0, 0, 0 };

        Info leftInfo = dfs(node->left);
        Info rightInfo = dfs(node->right);

        int numOfNodes = leftInfo.numOfNodes + rightInfo.numOfNodes + 1;
        int sum = leftInfo.sum + rightInfo.sum + node->val;
        int avg = sum / numOfNodes;
        int count = leftInfo.count + rightInfo.count;
        if (node->val == avg) {
            count += 1;
        }

        return { count, numOfNodes, sum };
    }
};