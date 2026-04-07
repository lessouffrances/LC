




class Solution 
{
    public:
    string minRemoveToMakeValid(string s) 
    {
        if (s.length() == 0) return "";

        int n = s.length();
        unordered_set<int> toRemove;
        stack<int> deck; // to store indices

        for (int i=0; i<n; i++) {
            if (isalnum(s[i])) continue;

            if (s[i] == ')') {
                if (!deck.empty()) {
                    deck.pop();
                } else {
                    toRemove.insert(i);
                }
            } else {
                deck.push(i);
            }
        }

        // if there are extra ( on stack
        while (!deck.empty()) {
            toRemove.insert(deck.top());
            deck.pop();
        }

        // consolidate and return
        string res = "";
        for (int i=0; i<n; i++) {
            if (toRemove.count(i)) continue;
            res += s[i];
        }
        
        return res;
    }
};