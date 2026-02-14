



class Solution 
{
    public:
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        if (!root) return {};

        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            
            vector<int> currLevel;
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
            if (currLevel.empty()) return res;
            res.push_back(currLevel);
        }
        
        return res;
    }
};