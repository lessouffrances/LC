class Solution
{
    public:
    int numOfOverpoweredNodes(TreeNode* root) 
    {
        dfs(root);
        return numOfOverpoweredNodes;
    }

    private:
    // post-order
    // defn: overpowered nodes: if the sum and the product of any pair of node 
    // from both left-subtree and right-subtree is no greater than the root val, 
    // then the root is a overpowered ndoe
    int numOfOverpoweredNodes = 0;
    set<TreeNode*> dfs(TreeNode* node) 
    {
        if (!node) return {};

        set<TreeNode*> leftNodes = dfs(node->left);
        set<TreeNode*> rightNodes = dfs(node->right);

        bool isRootOverpowered = false;

        // leaf nodes must be overpowered
        if (leftNodes.empty() && rightNodes.empty()) {
            isRootOverpowered = true;
        }

        bool hasBreak = false;
        // left or right exclusive
        if (leftNodes.empty() ^ rightNodes.empty()) {
            if (leftNodes.empty()) {
                // right subtree exists 
                for (auto& subNode : rightNodes) {
                    if (subNode->val > node->val) {
                        hasBreak = true;
                        break;
                    }
                }
            } else {
                // left subtree exists
                for (auto& subNode : leftNodes) {
                    if (subNode->val > node->val) {
                        hasBreak = true;
                        break;
                    }
                }
            }
        }

        if (!leftNodes.empty() && !rightNodes.empty()) {
            for (auto& leftNode : leftNodes) {
                for (auto& rightNode : rightNodes) {
                    int product = leftNode->val * rightNode->val;
                    int sum = leftNode->val + rightNode->val;

                    if (product > node->val || sum > node->val) {
                        hasBreak = true;
                        break;
                    }
                }
                if (hasBreak) break;
            }
        }

        if (!hasBreak) {
            isRootOverpowered = true;
        } 

        if (isRootOverpowered) {
            numOfOverpoweredNodes++;
        }

        // contribute
        leftNodes.insert(rightNodes.begin(), rightNodes.end());
        leftNodes.insert(node);
        return leftNodes;
    }
};