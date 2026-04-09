class Solution 
{
    public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) 
    {
        if (!root) return {};
        vector<int> result;

        result.push_back(root->val);
        if (!isLeaf(root)) {
            addLeftBoundary(root->left, result);
            addLeaves(root, result);
            addRightBoundary(root->right, result);
        }
        return result;
    }

    private:
    bool isLeaf(TreeNode* node) 
    {
        if (!node) return false;
        if (!node->left && !node->right) return true;
        return false;
    }

    // top-down
    // preorder
    void addLeftBoundary(TreeNode* node, vector<int>& result) 
    {
        if (!node || isLeaf(node)) return;
        
        result.push_back(node->val);
        if (node->left) {
            addLeftBoundary(node->left, result);
        } else {
            addLeftBoundary(node->right, result);
        }
    }

    // any traversal order can take this
    void addLeaves(TreeNode* node, vector<int>& result)
    {
        if (!node) return;
        addLeaves(node->left, result);
        if (isLeaf(node)) result.push_back(node->val);
        addLeaves(node->right, result);
    }

    // bottom-up
    // postorder
    void addRightBoundary(TreeNode* node, vector<int>& result) 
    {
        if (!node || isLeaf(node)) return;
        
        if (node->right) {
            addRightBoundary(node->right, result);
        } else {
            addRightBoundary(node->left, result);
        }
        result.push_back(node->val);
    }
};