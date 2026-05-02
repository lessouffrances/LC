class Solution 
{
    // preorder gives the root
    // and then see the inorder, it gives the segmentation
    // e.g.
    // preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
    // preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
    public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        if (preorder.empty() || inorder.empty()) return nullptr;

        // find the root
        TreeNode* root = new TreeNode(preorder[0]);
        int splitIdxVal = root->val;
        int splitIdx = findSplitIdxInorder(splitIdxVal, inorder);

        vector<int> inorderLeft = vector<int>(inorder.begin(), inorder.begin()+splitIdx);
        vector<int> inorderRight = vector<int>(inorder.begin()+splitIdx+1, inorder.end());
        vector<int> preorderLeft = vector<int>(preorder.begin()+1, preorder.begin()+splitIdx+1);
        vector<int> preorderRight = vector<int>(preorder.begin()+splitIdx+1, preorder.end());

        root->left = buildTree(preorderLeft, inorderLeft);
        root->right = buildTree(preorderRight, inorderRight);

        return root;
    }

    private:
    int findSplitIdxInorder(int splitIdxVal, vector<int>& inorder)
    {
        int n = inorder.size();
        for (int i=0; i<n; i++) {
            if (inorder[i] == splitIdxVal) {
                return i;
            }
        }
        return -1;
    }
};