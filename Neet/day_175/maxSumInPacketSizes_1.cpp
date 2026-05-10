class Solution
{
    public:
    // keep the k-size window and do not allow duplicates in window
    // update the maxSum as slide
    long maximizePacketSum(vector<int> packetSizes, int k)
    {
        if (packetSizes.empty() || packetSizes.size() < k) return -1;
        int n = packetSizes.size();
        unordered_map<int, int> windowCounter;

        int left = 0;
        int currSum = 0;
        int maxSum = -1;
        for (int right=0; right<n; right++) {
            windowCounter[packetSizes[right]]++;
            currSum += packetSizes[right];
            while (windowCounter[packetSizes[right]] > 1 || right - left + 1 > k) {
                windowCounter[packetSizes[left]]--;
                currSum -= packetSizes[left];
                left++;
            }
            if (right - left + 1 == k) {
                maxSum = max(maxSum, currSum);
            }
        }
        return maxSum;
    }
};