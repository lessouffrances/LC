


class Solution 
{
    public:
    int maxLevelSum(TreeNode* root) 
    {
        if (!root) return 0;

        queue<TreeNode* > q;
        q.push(root);

        int maxLevelSum = INT_MIN; // there might be negative vals
        int minLevel = 1;
        int level = 1;
        while (!q.empty()) {
            int size = q.size();

            int levelSum = 0;
            for (int i=0; i<size; i++) {
                auto node = q.front();
                q.pop();

                levelSum += node->val;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            if (levelSum > maxLevelSum) {
                maxLevelSum = levelSum;
                minLevel = level;
            }

            level++;
        }
        return minLevel;
    }
};