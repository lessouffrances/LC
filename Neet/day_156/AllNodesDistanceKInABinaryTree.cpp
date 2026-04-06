
class Solution 
{
    public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
    {
        if (!root) return {};
        markSourceAndBuildParentLookUp(root, target->val);
        return bfs(source, k);
    }

    private:
    TreeNode* source;
    unordered_map<TreeNode*, TreeNode*> parent;
    unordered_set<TreeNode* > visited;

    vector<int> bfs(TreeNode* source, int k)
    {
        queue<TreeNode* > q;
        q.push(source);
        visited.insert(source);

        vector<int> res;
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
    void markSourceAndBuildParentLookUp(TreeNode* node, int target)
    {
        if (!node) return;

        if (node->val == target) {
            source = node;
        }
        
        if (node->left) {
            markSourceAndBuildParentLookUp(node->left, target);
            parent[node->left] = node;
        }
        if (node->right) {
            markSourceAndBuildParentLookUp(node->right, target);
            parent[node->right] = node;
        }
    }
};