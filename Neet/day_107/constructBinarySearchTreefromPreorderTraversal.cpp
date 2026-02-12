

class Solution 
{
    public:
    TreeNode* bstFromPreorder(vector<int>& preorder) 
    {
        if (preorder.empty()) return nullptr;
        return preorderBuildBST(preorder, 0, INT_MIN, INT_MAX);
        
    }
    private:
    // preorder
    TreeNode* preorderBuildBST(vector<int>& preorder, int& idx, int minVal, int maxVal)
    {
        if (idx >= preorder.size()) return nullptr;
        int val = preorder[idx];

        if (val < minVal || val > maxVal) return nullptr;
        TreeNode* node = new TreeNode(val);
        idx++;
        node->left = preorderBuildBST(preorder, idx, minVal, val);
        node->right = preorderBuildBST(preorder, idx, val, maxVal);

        return node;
    }
};