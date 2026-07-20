struct TreeNode
{
   int val;
   TreeNode* left;
   TreeNode* right;
   TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

// overpowered node means that: if a root of a subtree is > all the nodes in its
// left and right subtree, and > all sum & product of one pair of nodes
//  from left and right subtree
class Solution
{
    public: 
    int numOfOverpoweredNodes(TreeNode* root)
    {
        if (!root) return 0;
        dfs(root);
        return count;
    }
    
    private:
    int count = 0;
    // post order
    unordered_set<int> dfs(TreeNode* node)
    {
        if (!node) return {};

        // left subtree
        unordered_set<int> leftSubtree = dfs(node->left);
        // right subtree
        unordered_set<int> rightSubtree = dfs(node->right);

        // comparison mechanism with the subtree root
        // see only left or only right
        // ^ XOR
        bool isOverpoweredNode = true;
        if (leftSubtree.empty() ^ rightSubtree.empty()) {
            if (leftSubtree.empty()) {
                for (int rightVal : rightSubtree) {
                    if (rightVal > node->val) {
                        isOverpoweredNode = false;
                        break;
                    }
                }
            } else {
                for (int leftVal : leftSubtree) {
                    if (leftVal > node->val) {
                        isOverpoweredNode = false;
                        break;
                    }
                }
            }
        }

        // pair node from both sides
        for (int leftVal : leftSubtree) {
            for (int rightVal : rightSubtree) {
                // sum
                if (leftVal + rightVal > node->val) {
                    isOverpoweredNode = false;
                    break;
                }
                // product
                if (leftVal * rightVal > node->val) {
                    isOverpoweredNode = false;
                    break;
                }
            }
            if (!isOverpoweredNode) break;
        }

        if (isOverpoweredNode) count++;

        // merge two into one
        leftSubtree.insert(rightSubtree.begin(), rightSubtree.end());
        leftSubtree.insert(node->val); 
        return leftSubtree;
    }
};