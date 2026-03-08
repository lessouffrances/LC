class Solution 
{
    public:
    int strStr(string haystack, string needle) 
    {
        // return haystack.find(needle);
        int windowSize = needle.size();
        int left = 0;

        while (left+windowSize <= haystack.size()) {
            string subStr = haystack.substr(left, windowSize);
            if (subStr == needle) return left;

            left ++;
        }
        return -1;
    }
};