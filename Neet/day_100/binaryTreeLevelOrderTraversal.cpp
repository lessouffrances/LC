




class Solution 
{
    public:
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        if (!root) return {};

        queue<TreeNode*> q;
        q.push(root);

        vector<vector<int>> res;
        while (!q.empty()) {
            vector<int> currLevel;
            int size = q.size();
            for (int i=0; i<size; i++) {
                auto node = q.front();
                q.pop();
                currLevel.push_back(node->val);

                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            if (!currLevel.empty()) {
                res.push_back(currLevel);
            }
        }
        
        return res;
    }
};