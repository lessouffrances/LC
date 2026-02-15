class Solution 
{
    public:
    string largestNumber(vector<int>& nums) 
    {
        if (nums.empty()) return "";

        vector<string> numStrs;
        for (int num : nums) {
            numStrs.push_back(to_string(num));
        }

        sort(numStrs.begin(), numStrs.end(), [](const auto& a, const auto& b) {
            return a + b > b + a;
        });
        if (numStrs[0] == "0") return "0";

        string res = "";
        for (auto& s : numStrs) {
            res += s;
        }
        return res;
    }
};