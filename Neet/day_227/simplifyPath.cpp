class Solution 
{
    public:
    string simplifyPath(string path) 
    {
        if (path.empty()) return "";

        stack<string> deck;
        string curr = "";

        for (char ch : path + "/") {
            if (ch == '/') {
                if (curr == "..") {
                    if (!deck.empty()) {
                        deck.pop();
                    }
                } else if (curr != "" && curr != ".") {
                    deck.push(curr);
                }
                curr = ""; // exit, reset
            } else {
                curr += ch;
            }
        }

        // build the res
        string res = "";
        while (!deck.empty()) {
            res = "/" + deck.top() + res;
            deck.pop();
        }
        return res.empty() ? "/" : res;
    }
};