#include <cstdio>
#include <string>
using namespace std;

class Solution {
    public:
    string oddLengthPalindrome(string s, int start) 
    {
        if (start-1 <0 || start+1 > s.size()-1) {
            return string(1, s[start]);
        }

        string res = string(1, s[start]);
        int gap = 1;
        while (start-gap >=0 && start+gap < s.size() 
        && s[start-gap] == s[start+gap]) {
            res.push_back(s[start+gap]);
            res.insert(res.begin(), 1, s[start-gap]);
            gap += 1;
        }
        return res;
    }

    string evenLengthPalindrome(string s, int start) 
    {
        if (start-1<0 || start>s.size()-1) {
            return "";
        }

        if (s[start-1] != s[start]) {
            return "";
        }

        string res = "";
        int gap = 1;
        while (start-gap >=0 && start+gap-1 < s.size() 
        && s[start-gap] == s[start+gap-1]) {
            res.push_back(s[start+gap-1]);
            res.insert(res.begin(), 1, s[start-gap]);
            gap += 1;
        }
        return res;
    }

    string longestPalindrome(string s) {
        if (s.empty()) return "";
        if (s.size() == 1) return s;

        string longestPalindrome = string(1, s[0]);
        for (int i=0; i<s.size(); i++) {
            string oddRes = oddLengthPalindrome(s, i);
            string evenRes = evenLengthPalindrome(s, i);
            string win;
            if (oddRes.size() > evenRes.size()) {
                win = oddRes;
            } else {
                win = evenRes;
            }

            if (win.size() > longestPalindrome.size()) {
                longestPalindrome = win;
            }
        }
        return longestPalindrome;
    }
};

int main()
{
    Solution solution = Solution();
    // string s = "babad"; // bab
    string s = "cbbd"; //bb
    // printf("%s\n", solution.oddLengthPalindrome(s, 1).c_str());
    // printf("%s\n", solution.evenLengthPalindrome(s, 2).c_str());
    printf("%s\n", solution.longestPalindrome(s).c_str());
}