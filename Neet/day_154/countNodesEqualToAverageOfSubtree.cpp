/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


struct Info 
{
    int count = 0; 
    int substreeSum = 0;
    int numOfNodes = 0; // num of nodes in the subtree
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
    // post-order
    Info dfs (TreeNode* node)
    {
        if (!node) return {};

        Info leftInfo = dfs(node->left);
        Info rightInfo = dfs(node->right);

        // compute incremental
        int numOfNodes = leftInfo.numOfNodes + rightInfo.numOfNodes + 1;
        int substreeSum = leftInfo.substreeSum + rightInfo.substreeSum + node->val;

        int avg = substreeSum / numOfNodes;
        int count = leftInfo.count + rightInfo.count;
        count += (avg == node->val) ? 1 : 0;

        return { count, substreeSum, numOfNodes };
    }
};