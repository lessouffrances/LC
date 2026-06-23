class Solution 
{
    // preorder gives the root
    // and then see the inorder, it gives the partition
    // e.g.
    //             r                          r
    // preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
    // recursive nature
    public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        if (preorder.empty() || inorder.empty()) return nullptr;

        TreeNode* root = new TreeNode(preorder[0]);
        int splitIdx = findIdxInorderArray(preorder[0], inorder);
        
        vector<int> inorderLeft = vector<int>(inorder.begin(), inorder.begin()+splitIdx);
        vector<int> inorderRight = vector<int>(inorder.begin()+splitIdx+1, inorder.end());
        vector<int> preorderLeft = vector<int>(preorder.begin()+1, preorder.begin()+splitIdx+1);
        vector<int> preorderRight = vector<int>(preorder.begin()+splitIdx+1, preorder.end());

        root->left = buildTree(preorderLeft, inorderLeft);
        root->right = buildTree(preorderRight, inorderRight);

        return root;
    }

    private:
    // return the idx for some val in inorder array
    int findIdxInorderArray(int val, vector<int>& inorder)
    {
        int n = inorder.size();
        for (int i=0; i<n; i++) {
            if (val == inorder[i]) return i;
        }
        return -1;
    }
};