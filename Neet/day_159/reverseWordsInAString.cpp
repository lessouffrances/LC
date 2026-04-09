class Solution 
{
    public:
    string reverseWords(string s) 
    {
        stringstream ss(s);
        string token;
        vector<string> res;

        while (getline(ss, token, ' ')) {
            if (!token.empty()) {
                res.push_back(token);
            }
        }

        return merge(res);
    }

    private:
    string merge(vector<string>& words)
    {
        int n = words.size();
        string res = "";
        for (int i=n-1; i>0; i--) {
            res += words[i] + " ";
        }
        res += words[0];
        return res;
    }
};