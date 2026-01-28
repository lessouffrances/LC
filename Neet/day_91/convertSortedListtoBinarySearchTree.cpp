class Solution 
{
    public:
    TreeNode* sortedListToBST(ListNode* head) 
    {
        if (!head) return nullptr;

        vector<int> nums;
        while (head) {
            nums.push_back(head->val);
            head = head->next;
        }

        int n = nums.size();
        return dfs(nums, 0, n-1);
    }
    private:
    TreeNode* dfs(vector<int>& nums, int left, int right)
    {
        if (nums.empty() || left > right) return nullptr;

        int mid = left + (right - left) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = dfs(nums, left, mid-1);
        root->right = dfs(nums, mid+1, right);
        return root;
    }
};