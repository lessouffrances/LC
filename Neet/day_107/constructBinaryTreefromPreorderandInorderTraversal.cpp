

// preorder = [3,9,20,15,7]
// inorder = [9,3,15,20,7]

class Solution 
{
    public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        if (preorder.empty() || inorder.empty()) return nullptr;

        int rootVal = preorder[0];
        TreeNode* root = new TreeNode(rootVal);

        // split the inorder array by this rootVal
        int splitIdx = getRootIdx(inorder, rootVal);

        // recurse on left
        vector<int> inorderLeft = vector<int>(inorder.begin(), inorder.begin()+splitIdx);
        vector<int> preorderLeft = vector<int>(preorder.begin()+1, preorder.begin()+splitIdx+1);
        root->left = buildTree(preorderLeft, inorderLeft);

        // recurse on right
        vector<int> inorderRight = vector<int>(inorder.begin()+splitIdx+1, inorder.end());
        vector<int> preorderRight = vector<int>(preorder.begin()+splitIdx+1, preorder.end());
        root->right = buildTree(preorderRight, inorderRight);

        return root;
    }
    private:
    int getRootIdx(vector<int>& inorder, int rootVal)
    {
        for (int i=0; i<inorder.size(); i++) {
            if (inorder[i] == rootVal) return i;
        }
        return -1;
    }
};