class Solution 
{
   public:
   int maxArea(vector<int>& height) 
   {
      if (height.empty()) return 0;
      int l = 0, r = height.size() - 1;
      int maxArea = 0;

      while (l < r) {
        int currArea = min(height[l], height[r]) * (r-l);
        maxArea = max(maxArea, currArea);

        if (height[l] < height[r]) {
            l++;
        } else {
            r--;
        }
      }
      return maxArea;
   }
};