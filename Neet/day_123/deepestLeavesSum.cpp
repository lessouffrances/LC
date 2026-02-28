


class Solution 
{
    public:
    int deepestLeavesSum(TreeNode* root) 
    {
        if (!root) return 0;

        int targetLevel = getHeight(root);
        
        queue<TreeNode*> q;
        q.push(root);
        int level = 1;

        while (!q.empty()) {
            int size = q.size();
            int levelSum = 0;
            for (int i=0; i<size; i++) {
                auto node = q.front();
                q.pop();
                
                if (level == targetLevel) {
                    levelSum += node->val;
                }

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            if (level == targetLevel) return levelSum;
            level++;
        }
        return -1;
    }

    private:
    int getHeight(TreeNode* node)
    {
        if (!node) return 0;
        return 1 + max(getHeight(node->left), getHeight(node->right));
    }
};