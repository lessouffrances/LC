

class Solution {
    public:
    bool repeatedSubstringPattern(string s) {
        string doubled = s + s;
        if (doubled.substr(1, doubled.size()-2).find(s) != -1) return true;
        return false;
    }
};