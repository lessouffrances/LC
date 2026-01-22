class Solution 
{
  public:
  int minEatingSpeed(vector<int>& piles, int h) {
    if (piles.empty()) return 0;

    int right = *max_element(piles.begin(), piles.end());
    int left = 1;

    while (left <= right) {
      int k = left + (right - left) / 2;
      if (canFinishAll(piles, h, k)) {
        right = k-1;
      } else {
        left = k+1;
      }
    }
    return left;
  }
  // {3, 6, 7, 11}, h = 8, k = 4
  private:
  bool canFinishAll(vector<int>& piles, int h, int k)
  {
    if (piles.empty()) return 0;
    int n = piles.size();

    long long totalTimeNeeded = 0; 

    for (int i=0; i<n; i++) { // 0  1  2  3
      int numOfBananas = piles[i]; // 3  6  7  11

      long long neededTime = 0; // 0  0  0  0
      if (numOfBananas % k == 0) { // f  f  f  f
        neededTime = numOfBananas / k;
      } else {
        neededTime = (numOfBananas + k - 1) / k; // 1  2  2  3
      }
      totalTimeNeeded += neededTime; // 1  3  5  8
    }

    return totalTimeNeeded <= h;
  }
};