class Solution 
{
    public:
    string simplifyPath(string path) 
    {
        if (path.length() == 0) return "";

        stack<string> deck;
        string curr = "";

        for (char ch : path+"/") {
            // signalf for curr to exit
            if (ch == '/') {

                if (curr == "..") {
                    // the last dir was redundant
                    if (!deck.empty()) {
                        deck.pop();
                    }
                } else if (curr != "." && curr != "") {
                    // only retained if not . or ""
                    deck.push(curr);
                }
                curr = ""; // reset
            } else {
                curr += ch;
            }
        }
        string res = "";
        while (!deck.empty()) {
            res = '/' + deck.top() + res;
            deck.pop();
        }
        return res.empty() ? "/" : res;
    }
};