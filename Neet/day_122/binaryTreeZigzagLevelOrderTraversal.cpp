

class Solution 
{
    public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        if (!root) return {};
        queue<TreeNode*> q;
        q.push(root);

        // if even level: from left to right
        // if odd level: from right to left
        vector<vector<int>> res;
        int level = 0;
        while (!q.empty()) {
            int size = q.size();
            vector<int> currLevelVals;

            for (int i=0; i<size; i++) {
                auto node = q.front();
                q.pop();
                currLevelVals.push_back(node->val);

                // FIFO
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            if (level % 2 != 0) {
                reverse(currLevelVals.begin(), currLevelVals.end());
            }
            res.push_back(currLevelVals);
            level++;
        }
        return res;
    }
};