class Solution 
{
    public:
    int calculate(string s) 
    {
        if (s.length() == 0) return 0;
        int n = s.length();
        int i = 0;

        stack<int> deck;
        while (i<n) {
            while (i<n && s[i] == ' ') i++;

            if (s[i] == '*' || s[i] == '/') {
                char op = s[i];
                i++;

                while (i<n && s[i] == ' ') i++;
                string currStr = "";
                while (i<n && isdigit(s[i])) {
                    currStr += s[i];
                    i++;
                }

                if (currStr.empty()) return 0;
                int currNum = stoi(currStr);
                int prevNum = deck.top();
                deck.pop();
                deck.push( op == '*' ? currNum * prevNum : prevNum / currNum);

            } else if (s[i] == '+' || s[i] == '-') {
                char op = s[i];
                i++;

                while (i<n && s[i] == ' ') i++;
                string currStr = "";
                while (i<n && isdigit(s[i])) {
                    currStr += s[i];
                    i++;
                }

                if (currStr.empty()) return 0;
                int currNum = stoi(currStr);

                deck.push( op == '+' ? currNum : -currNum);

            } else {
                i++;
            }
        }

        int res = 0;
        while (!deck.empty()) {
            res += deck.top();
            deck.pop();
        }
        return res;
    }
};