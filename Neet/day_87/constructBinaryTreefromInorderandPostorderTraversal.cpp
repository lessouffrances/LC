// inorder = [9,3,15,20,7]
// postorder = [9,15,7,20,3]
class Solution 
{
    public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        if (postorder.empty() || inorder.empty()) return nullptr;

        TreeNode* root = new TreeNode(postorder.back());
        int splitIdx = getIdxInorder(inorder, postorder.back());

        // recurse on left
        vector<int> inorderLeft = vector<int>(inorder.begin(), inorder.begin()+splitIdx);
        vector<int> postorderLeft = vector<int>(postorder.begin(), postorder.begin()+splitIdx);
        root->left = buildTree(inorderLeft, postorderLeft);

        // recurse on right
        vector<int> inorderRight = vector<int>(inorder.begin()+splitIdx+1, inorder.end());
        vector<int> postorderRight = vector<int>(postorder.begin()+splitIdx, postorder.end()-1);
        root->right = buildTree(inorderRight, postorderRight);

        return root;
    }

    private:
    int getIdxInorder(vector<int>& inorder, int val)
    {
        if (inorder.empty()) return -1;

        for (int i=0; i<inorder.size(); i++) {
            if (inorder[i] == val) {
                return i;
            }
        }
        return -1;
    }
};