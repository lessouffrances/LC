class Solution 
{
    public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) 
    {
        unordered_map<int, TreeNode*> valToNode;
        unordered_set<int> childVals;
        
        for (auto& d : descriptions) {
            int parentVal = d[0], childVal = d[1], isLeft = d[2];
            if (!valToNode.count(parentVal)) {
                valToNode[parentVal] = new TreeNode(parentVal);
            } 
            if (!valToNode.count(childVal)) {
                valToNode[childVal] = new TreeNode(childVal);
            }
            childVals.insert(childVal);

            if (isLeft) {
                valToNode[parentVal]->left = valToNode[childVal];
            } else {
                valToNode[parentVal]->right = valToNode[childVal];
            }
        }

        // root: which val is not in the childVals
        for (auto& [val, node] : valToNode) {
            if (!childVals.count(val)) return node;
        }
        return nullptr;
    }
};