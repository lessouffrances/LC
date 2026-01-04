struct TreeNode
{
   int val;
   TreeNode* left;
   TreeNode* right;
   TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

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
      unordered_set<int> leftVals = dfs(node->left);
      unordered_set<int> rightVals = dfs(node->right);
      bool isOverpowered = true;
      
      // only one-sided
      if (leftVals.empty() ^ rightVals.empty()) {
         if (leftVals.empty()) {
            for (int val : rightVals) {
               if (val < node->val) {
                  isOverpowered = false;
                  break;
               }
            }
         }
         if (rightVals.empty()) {
            for (int val : leftVals) {
               if (val < node->val) {
                  isOverpowered = false;
                  break;
               }
            }
         }
      }

      // two-sided
      if (!leftVals.empty() && !rightVals.empty()) {
         for (int leftVal : leftVals) {
            for (int rightVal : rightVals) {
               if (leftVal + rightVal > node->val 
                   || leftVal * rightVal > node->val) {
                  isOverpowered = false;
                  break;
               }
            }
            if (!isOverpowered) break;
         }
      }

      if (isOverpowered) count++;

      // contribute to return
      unordered_set<int> subtree;
      subtree.insert(node->val);
      for (int leftVal : leftVals) {
         subtree.insert(leftVal);
      }
      for (int rightVal : rightVals) {
         subtree.insert(rightVal);
      }
      return subtree;
   }
};


