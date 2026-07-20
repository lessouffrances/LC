class Solution 
{
    public:
    int maxVowels(string s, int k) 
    {
        if (s.empty()) return 0;
        int n = s.length();

        // initial state
        int right = k-1;
        int left = 0;
        auto isVowel = [](char ch) {
            return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
        };
        int currCount = count_if(s.begin(), s.begin()+k, isVowel);
        int maxCount = currCount;

        for (int right=k; right<n; right++) {
            if (isVowel(s[right])) currCount++;
            if (isVowel(s[right-k])) currCount--;
            maxCount = max(maxCount, currCount);
        }
        return maxCount;
    }
};