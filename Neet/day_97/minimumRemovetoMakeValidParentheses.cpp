class Solution 
{
    public:
    string minRemoveToMakeValid(string s) 
    {
        if (s.length() == 0) return "";
        int n = s.length();
        stack<int> deck;
        unordered_set<int> toRemove;

        for (int i=0; i<n; i++) {
            if (s[i] == ')') {
                if (!deck.empty()) {
                    deck.pop();
                } else {
                    toRemove.insert(i);
                }
            } else if (s[i] == '(') {
                deck.push(i);
            }
        }

        while (!deck.empty()) {
            toRemove.insert(deck.top());
            deck.pop();
        }

        string res = "";
        for (int i=0; i<n; i++) {
            if (!toRemove.count(i)) {
                res += s[i];
            }
        }
        return res;
    }
};