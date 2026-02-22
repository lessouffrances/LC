



class Solution 
{
    public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) 
    {
        return dfs(root).first;
    }
    private:
    pair<TreeNode*, int> dfs(TreeNode* node)
    {
        if (!node) return {nullptr, -1};

        auto [leftNode, leftHeight] = dfs(node->left);
        auto [rightNode, rightHeight] = dfs(node->right);

        if (leftHeight == rightHeight) return {node, leftHeight+1};
        if (leftHeight > rightHeight) return {leftNode, leftHeight+1};
        else return {rightNode, rightHeight+1};
    }
    










    // preorder
    TreeNode* deepestLeaf = nullptr;
    TreeNode* target = nullptr;
    int maxDepth = -1;
    void dfs(TreeNode* node, int depth)
    {
        if (!node) return;
        if (!node->right && !node->left) {
            if (depth > maxDepth) {
                maxDepth = depth;
                deepestLeaf = node;
            }
        }

        dfs(node->left, depth+1);
        dfs(node->right, depth+1);
    }
    // postorder
    int getDepth(TreeNode* target, TreeNode* node)
    {
        if (!node) return -1;
        if (node == target) return 0;

        int left = getDepth(target, node->left);
        int right = getDepth(target, node->right);

        if (left != -1) {
            return 1 + left;
        }
        if (right != -1) {
            return 1 + right;
        }
        return -1;
    }
    //postorder
    int getHeight(TreeNode* node)
    {
        if (!node) return 0;
        int left = getHeight(node->left);
        int right = getHeight(node->right);
        
        return 1 + max(left, right);
    }
};