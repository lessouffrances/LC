class Solution
{
    public:
    long maximizePacketSum(vector<int> packetSizes, int k)
    {
        if (packetSizes.empty()) return 0;
        int n = packetSizes.size();
        unordered_map<int, int> windowCounter;
        int maxSum = INT_MIN;
        int currSum = 0;
        int left = 0;

        for (int right=0; right<n; right++) {
            currSum += packetSizes[right];
            windowCounter[packetSizes[right]]++;
            while (windowCounter[packetSizes[right]] > 1 || right-left+1>k) {
                currSum -= packetSizes[left];
                windowCounter[packetSizes[left]]--;
                left++;
            } 
            if (right-left+1 == k) {
                maxSum = max(maxSum, currSum);
            }
        }
        return maxSum;
    }
};