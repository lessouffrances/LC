class Solution 
{
    public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) 
    {
        unordered_map<int, TreeNode*> valToNodes;
        unordered_set<int> childVals;

        for (auto& d : descriptions) {
            int parentVal = d[0];
            int childVal = d[1];
            bool isLeft = (d[2] == 1) ? true : false;

            if (!valToNodes.count(parentVal)) {
                valToNodes[parentVal] = new TreeNode(parentVal);
            }
            if (!valToNodes.count(childVal)) {
                valToNodes[childVal] = new TreeNode(childVal);
            }
            childVals.insert(childVal);

            if (isLeft) {
                valToNodes[parentVal]->left = valToNodes[childVal];
            } else {
                valToNodes[parentVal]->right = valToNodes[childVal];
            }
        }

        // which one is root node
        for (auto& [val, node] : valToNodes) {
            if (!childVals.count(val)) return node;
        }
        return nullptr;
    }
};
