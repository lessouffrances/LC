
class Solution 
{
    public:
    vector<int> rightSideView(TreeNode* root) 
    {
        if (!root) return {};

        unordered_set<int> seen;
        queue<pair<TreeNode*, int>> q;
        q.push( { root, 0} );
        vector<int> res; 

        while (!q.empty()) {
            int size = q.size();
            for (int i=0; i<size; i++) {
                auto [node, currRow] = q.front();
                q.pop();

                if (!seen.count(currRow)) {
                    res.push_back(node->val);
                    seen.insert(currRow);
                }
                if (node->right) {
                    q.push( { node->right, currRow+1 });
                }
                if (node->left) {
                    q.push( { node->left, currRow+1 });
                }
            }
        }
        return res;
    }
};