// T: O(N)
// S: O(N)

class Solution 
{
    public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
    {
        if (!root) return {};
        buildParentAndMarkSrc(root, target);

        // bfs
        queue<TreeNode*> q;
        q.push(source);
        unordered_set<TreeNode*> visited;
        visited.insert(source);

        while (!q.empty()) {
            int size = q.size();
            vector<int> currLevelVals;
            for (int i=0; i<size; i++) {
                auto node = q.front();
                q.pop();

                if (k == 0) currLevelVals.push_back(node->val);
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
            if (k == 0) return currLevelVals;
            k--;
        }
        return {};
    }

    private:
    unordered_map<TreeNode*, TreeNode*> parent;
    TreeNode* source;

    // chore
    // choose any traversal order: preorder
    void buildParentAndMarkSrc(TreeNode* node, TreeNode* target)
    {
        if (!node) return;
        if (node->left) parent[node->left] = node;
        if (node->right) parent[node->right] = node;

        // identify the source node
        if (node == target) source = node;
        // recurse
        buildParentAndMarkSrc(node->left, target);
        buildParentAndMarkSrc(node->right, target);
    }
};