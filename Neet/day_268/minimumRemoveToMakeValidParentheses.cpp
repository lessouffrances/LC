class Solution 
{
    public:
    string minRemoveToMakeValid(string s) 
    {
        if (s.length() == 0) return "";
        int n = s.length();
        unordered_set<int> idxesToRemove;
        stack<pair<char, int>> deck; // {ch, idx}

        for (int i=0; i<n; i++) {
            if (s[i] == ')') {
                if (!deck.empty() && deck.top().first == '(') {
                    deck.pop();
                } else {
                    idxesToRemove.insert(i);
                }
            } else if (s[i] == '(') {
                deck.push( {s[i], i} );
            }
        }

        while (!deck.empty()) {
            idxesToRemove.insert(deck.top().second); deck.pop();
        }

        string res = "";
        for (int i=0; i<n; i++) {
            if (!idxesToRemove.count(i)) res += s[i];
        }
        return res;
    }
};