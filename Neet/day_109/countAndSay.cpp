class Solution 
{
    public:
    string countAndSay(int n) 
    {
        string prev = "1";
        for (int i=0; i<n-1; i++) {
            prev = countAndSayHelper(prev);
        }
        return prev;
    }
    private:
    //                                l   r
    // "2  2  3  3  1  4  4  4  4  4  1  1"
    // 
    string countAndSayHelper(const string& s)
    {
        if (s.length() == 0) return "";
        int n = s.length();

        int left = 0, right = 0;
        pair<char, int> count = {0, 0}; //{0,0}
        string res = "";

        for (right=0; right<n; right++) {
            if (s[right] == s[left]) {
                count.first = s[right]; 
                count.second++;  //{1,2}
            } else {
                res += to_string(count.second) + count.first; //"22231154"
                left = right;
                count = {s[right], 1}; //{1,1}
            }
        }

        res += to_string(count.second) + count.first;
        return res;
    }
};