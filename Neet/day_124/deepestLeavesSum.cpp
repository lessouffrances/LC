class Solution 
{
    public:
    int deepestLeavesSum(TreeNode* root) 
    {
        if (!root) return 0;

        queue<TreeNode*> q;
        q.push(root);

        // which is the layer
        int maxLevel = getHeight(root);
        int level = 0;
        while (!q.empty()) {
            int size = q.size();


            int levelSum = 0;
            for (int i=0; i<size; i++) {
                auto node = q.front();
                q.pop();

                levelSum += node->val;

                if (node->left) {
                    q.push(node->left);
                } 
                if (node->right) {
                    q.push(node->right);
                }
            }
            level++;
            if (level == maxLevel) return levelSum;
        }
        return -1;
    }
    private:
    int getHeight(TreeNode* node)
    {
        if (!node) return 0;

        int left = getHeight(node->left);
        int right = getHeight(node->right);

        return 1 + max(left, right);
    }
};