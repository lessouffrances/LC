


class Solution 
{
    public:
    int maxLevelSum(TreeNode* root) 
    {
        if (!root) return 0;

        queue<TreeNode* > q;
        q.push(root);

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
            sumToLevel[levelSum].insert(level);
            level++;
        }

        // after the info collection
        // the level with the greatest sum is the last one in the map
        // return the first one in the set
        return *sumToLevel.rbegin()->second.begin();
    }
    private:
    map<int, set<int>> sumToLevel;  // sum is increasing 

};