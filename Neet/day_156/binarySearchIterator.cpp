



class BSTIterator 
{
    public:
    BSTIterator(TreeNode* root) 
    {
        dfs(root);
        size = inOrder.size();
    }
    
    int next() 
    {
        int res = -1;
        if (iter < size) {
            res = inOrder[iter];
            iter++;
        }
        return res;
    }
    
    bool hasNext() 
    {
        if (iter<size) return true;
        return false;
    }

    private:
    int iter = 0;
    int size = 0;
    vector<int> inOrder;
    void dfs(TreeNode* root)
    {
        if (!root) return;

        dfs(root->left);
        if (root != nullptr) {
            inOrder.push_back(root->val);
        }
        dfs(root->right);
    }
};

