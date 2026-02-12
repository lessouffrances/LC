







class Solution 
{
    public:
    string minRemoveToMakeValid(string s) 
    {
        if (s.length() == 0) return "";
        int n = s.length();
        unordered_set<int> toRemove;
        stack<int> deck;

        for (int i=0; i<n; i++) {
            if (s[i] == '(') {
                deck.push(i);
            } else if (s[i] == ')') {
                if (deck.empty()) {
                    toRemove.insert(i);
                } else {
                    deck.pop();
                }
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