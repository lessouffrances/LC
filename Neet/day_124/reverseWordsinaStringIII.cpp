class Solution 
{
    public:
    string reverseWords(string s) 
    {    
        vector<string> tokens = tokenize(s);
        string res = "";
        int n = tokens.size();
        for (int i=0; i<n-1; i++) {
            res += tokens[i] + " ";
        }
        res += tokens[n-1];
        return res;
    }
    private:
    vector<string> tokenize(const string& s)
    {
        vector<string> res;
        stringstream ss(s);
        string token;

        while (getline(ss, token, ' ')) {
            reverse(token.begin(), token.end());
            res.push_back(token);
        }
        return res;
    }
};