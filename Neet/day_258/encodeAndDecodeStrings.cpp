class Codec 
{
    public:
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) 
    {
        string res = "";
        for (auto& str : strs) {
            for (char ch : str) {
                res += to_string(ch-'a')+","; // delimiter for each char
            }
            res += "#"; // delimiter for each word
        }
        return res;
    }
    
    // Decodes a single string to a list of strings.
    vector<string> decode(string s) 
    {
        vector<string> words = split(s, '#');
        vector<string> res;

        for (const auto& w : words) {
            vector<string> numStrs = split(w, ',');
            string currStr = "";

            for (auto& numStr : numStrs) {
                int num = stoi(numStr);
                currStr += num+'a';
            }
            res.push_back(currStr);
        }
        return res;
    }

    private:
    vector<string> split(const string& s, char delimiter)
    {
        vector<string> tokens;
        stringstream ss(s);
        string token;
        while (getline(ss, token, delimiter)) {
            tokens.push_back(token);
        }
        return tokens;
    }
};
    
    