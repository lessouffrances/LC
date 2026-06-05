class Solution 
{
    public:
    int strStr(string haystack, string needle) 
    {
        int windowSize = needle.length();
        int n = haystack.size();
        int left = 0;
        while (left+windowSize <= n) {
            string subStr = haystack.substr(left, windowSize);
            if (subStr == needle) return left;
            left++;
        }
        return -1;
    }
};