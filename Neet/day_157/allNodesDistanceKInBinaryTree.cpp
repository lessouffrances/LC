




class Solution 
{
    public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
    {
        if (!root) return {};

        buildParentAndMarkSource(root, target->val);

        return bfs(source, k);


    }

    private:
    unordered_map<TreeNode*, TreeNode*> parent;
    TreeNode* source;
    unordered_set<TreeNode* > visited;

    // bfs
    vector<int> bfs(TreeNode* source, int k) 
    {
        vector<int> res;
        queue<TreeNode* > q;
        q.push(source);
        visited.insert(source);

        while (!q.empty()) {
            int size = q.size();
            for (int i=0; i<size; i++) {
                auto node = q.front();
                q.pop();

                if (k == 0) {
                    res.push_back(node->val);
                }
                if (node->left && !visited.count(node->left)) {
                    q.push(node->left);
                    visited.insert(node->left);
                } 
                if (node->right && !visited.count(node->right)) {
                    q.push(node->right);
                    visited.insert(node->right);
                } 
                if (parent.count(node) && !visited.count(parent[node])) {
                    q.push(parent[node]);
                    visited.insert(parent[node]);
                }
            }
            k--;
        }

        return res;
    }
    // preorder
    void buildParentAndMarkSource(TreeNode* node, int target)
    {
        if (!node) return;

        if (node->val == target) {
            source = node;
        }

        if (node->left) {
            parent[node->left] = node;
            buildParentAndMarkSource(node->left, target);
        }
        if (node->right) {
            parent[node->right] = node;
            buildParentAndMarkSource(node->right, target);
        }
    }
};