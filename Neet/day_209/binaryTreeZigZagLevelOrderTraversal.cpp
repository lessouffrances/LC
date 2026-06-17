class Solution 
{
    public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        if (!root) return {};

        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> res;

        // if level is odd, reverse
        int level = 0;
        while (!q.empty()) {
            int size = q.size();
            vector<int> currLevelVals;

            for (int i=0; i<size; i++) {
                auto node = q.front();
                q.pop();

                currLevelVals.push_back(node->val);
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            if (!currLevelVals.empty() && level % 2 != 0) {
                reverse(currLevelVals.begin(), currLevelVals.end());
            }
            level++;
            res.push_back(currLevelVals);
        }
        return res;
    }
};