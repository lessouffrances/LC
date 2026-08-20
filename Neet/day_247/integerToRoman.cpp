class Solution 
{
    public:
    string intToRoman(int num) 
    {
        // the map has to be from large to small
        vector<pair<int, string>> numToRoman =
        {
            {1000, "M"},
            {900, "CM"},
            {500, "D"},
            {400, "CD"},
            {100, "C"},
            {90, "XC"},
            {50, "L"},
            {40, "XL"},
            {10, "X"},
            {9, "IX"},
            {5, "V"},
            {4, "IV"},
            {1, "I"}
        };

        string res = "";
        for (auto& [val, roman] : numToRoman) {
            while (num >= val) {
                res += roman;
                num -= val;
            }
        }
        return res;
    }
};