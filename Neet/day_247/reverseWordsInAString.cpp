class Solution 
{
    public:
    string reverseWords(string s) 
    {
        if (s.length() == 0) return "";

        stringstream ss(s);
        vector<string> tokens;
        string token;
        while (getline(ss, token, ' ')) {
            if (!token.empty()) {
                tokens.push_back(token);
            }
        }

        string res = "";
        for (int i=tokens.size()-1; i>=0; i--) {
            res += tokens[i];
            if (i > 0) res += " ";
        }
        return res;
    }
};