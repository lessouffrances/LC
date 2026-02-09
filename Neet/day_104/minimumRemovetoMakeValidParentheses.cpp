




// s = "lee(t(c)o)de)"


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
                if (!deck.empty()) {
                    deck.pop();
                } else {
                    toRemove.insert(i);
                }
            }
        }

        while (!deck.empty()) {
            toRemove.insert(deck.top());
            deck.pop();
        }

        string ans = "";
        for (int i=0; i<n; i++) {
            if (!toRemove.count(i)) {
                ans += s[i];
            }
        }
        return ans;
    }
};