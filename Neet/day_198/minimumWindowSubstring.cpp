class Solution
{
public:
    bool validWindow(vector<int>& windowCounter,
                     vector<int>& tBenchmark)
    {
        for (int i = 0; i < 128; i++) {
            if (windowCounter[i] < tBenchmark[i])
                return false;
        }
        return true;
    }

    string minWindow(string s, string t)
    {
        if (s.length() < t.length())
            return "";

        vector<int> tBenchmark(128, 0);
        for (char ch : t) {
            tBenchmark[ch]++;
        }

        vector<int> windowCounter(128, 0);

        int left = 0;
        int minLen = INT_MAX;
        int startIdx = 0;

        for (int right = 0; right < s.length(); right++) {

            windowCounter[s[right]]++;

            while (validWindow(windowCounter, tBenchmark)) {
                int currLen = right - left + 1;
                if (currLen < minLen) {
                    minLen = currLen;
                    startIdx = left;
                }

                windowCounter[s[left]]--;
                left++;
            }
        }

        return minLen == INT_MAX
            ? ""
            : s.substr(startIdx, minLen);
    }
};