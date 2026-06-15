class Solution 
{
    public:
    TreeNode* sortedListToBST(ListNode* head) 
    {
        if (!head) return nullptr;

        vector<int> vals;
        while (head) {
            vals.push_back(head->val);
            head = head->next;
        }
        return buildBalancedBST(vals, 0, vals.size()-1);
    }

    private:
    TreeNode* buildBalancedBST(vector<int>& nums, int left, int right)
    {
        if (left > right) return nullptr;
        int mid = left + (right - left) / 2;

        TreeNode* node = new TreeNode(nums[mid]);
        node->left = buildBalancedBST(nums, left, mid-1);
        node->right = buildBalancedBST(nums, mid+1, right);
        return node;
    }
};