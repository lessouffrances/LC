class Solution 
{
    public:
    int maxLevelSum(TreeNode* root) 
    {
        if (!root) return 0;

        queue<TreeNode*> q;
        q.push(root);
        int minLevel = 1; // start at 1
        int maxSum = INT_MIN; // if negative nodes
        int currLevel = 1;

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
            if (levelSum > maxSum) {
                minLevel = currLevel;
                maxSum = levelSum;
            }
            currLevel++;
        }
        return minLevel;
    }
};