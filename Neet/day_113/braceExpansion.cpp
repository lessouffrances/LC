class Solution 
{
    public:
    vector<string> expand(string s) 
    {
        if (s.empty()) return {};
        int n = s.length();

        if (s.find('{') == string::npos) {  
            return { s };
        }

        vector<vector<char>> options;
        stack<char> deck;
        for (int i=0; i<n; i++) {
            char ch = s[i];

            if (ch != '{' && ch != '}' && ch != ',') {
                deck.push(ch);
                continue;
            }

            if (ch == '}') {
                vector<char> group;
                while (!deck.empty() && deck.top() != '{') {
                    group.push_back(deck.top());
                    deck.pop();
                }
                deck.pop(); // pop the {
                sort(group.begin(), group.end());  
                options.push_back(group);

            } else if (ch == '{') {
                // Each standalone char before '{' is its own group
                while (!deck.empty()) {
                    vector<char> group = {deck.top()};
                    options.push_back(group);
                    deck.pop();
                }
                deck.push(ch);
            } 
        }

        // Each remaining char is its own group
        while (!deck.empty()) {
            vector<char> group = {deck.top()};
            options.push_back(group);
            deck.pop();
        }
        
        vector<char> startPath;
        dfs(0, startPath, options);
        return res;
    }
    
    private:
    vector<string> res;
    void dfs(int groupIdx, vector<char>& currPath, vector<vector<char>>& options)
    {
        if (groupIdx == options.size()) {
            string s = string(currPath.begin(), currPath.end());
            res.push_back(s);
            return;
        }

        vector<char> currGroup = options[groupIdx];
        for (int i=0; i<currGroup.size(); i++) {
            char ch = currGroup[i];
            currPath.push_back(ch);
            dfs(groupIdx+1, currPath, options);
            currPath.pop_back();
        }
    }
};