
// s = "lee(t(c)o)de)"
// "lee(t(c)o)de"
// deck = [ ) ]

// set up a stack, only push up the parentheses,
// signal to exit stack: close, if there is a corresponding open on stack, pop it, 
// otherwise, memorize the idx for delete

class Solution 
{
    public:
    string minRemoveToMakeValid(string s) 
    {
        if (s.length() == 0) return "";
        int n = s.length();

        stack<int> deck;
        unordered_set<int> idxesToRemove;

        for (int i=0; i<n; i++) {
            if (s[i] == ')') {
                if (!deck.empty()) {
                    deck.pop();
                } else {
                    idxesToRemove.insert(i);
                }
            } else if (s[i] == '(') {
                deck.push(i);
            }
        }

        // if there are extra ( on stack
        while (!deck.empty()) {
            idxesToRemove.insert(deck.top());
            deck.pop();
        }

        string res = "";
        for (int i=0; i<n; i++) {
            if (!idxesToRemove.count(i)) res += s[i];
        }
        return res;
    }
};