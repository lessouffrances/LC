// struct TreeNode
// {
//     int val;
//     TreeNode* left;
//     TreeNode* right;

//     TreeNode(): val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
// };


class Solution 
{
    public:
    bool findTarget(TreeNode* root, int k) 
    {
        return dfs(root, k);
    }

    private:
    // preorder
    unordered_set<int> seen;
    bool dfs(TreeNode* node, int k)
    {
        if (!node) return false;

        int diff = k - node->val;
        if (seen.count(diff)) return true;
        seen.insert(node->val);

        return dfs(node->left, k) || dfs(node->right, k);
    }
};