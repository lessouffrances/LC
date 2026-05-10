class Solution
{
    public:
    long maximizePacketSum(vector<int> packetSizes, int k)
    {
        if (packetSizes.empty() || packetSizes.size() < k) return -1;

        int n = packetSizes.size();
        unordered_map<int, int> windowCounter;

        int left = 0;
        long maxSum = -1;
        long currSum = 0;

        for (int right=0; right<n; right++) {
            currSum += packetSizes[right];
            windowCounter[packetSizes[right]]++;
            while (windowCounter[packetSizes[right]] > 1 || right - left + 1 > k) {
                currSum -= packetSizes[left];
                windowCounter[packetSizes[left]]--;
                if (windowCounter[packetSizes[left]] == 0) {
                    windowCounter.erase(packetSizes[left]);
                }
                left++;
            }
            if (windowCounter.size() == k) {
                maxSum = max(maxSum, currSum);
            }
        }
        return maxSum;
    }
};