class Solution 
{
    public:
    int calculate(string s) 
    {
        stack<int> deck;
        int num = 0;
        char op = '+';
        int n = s.length();

        for (int i=0; i<n; i++) {
            char c = s[i];

            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            }

            if (!isdigit(c) && c != ' ' || i == n-1) {
                if (op == '*') {
                    int top = deck.top();
                    deck.pop();
                    deck.push(top * num);
                } else if (op == '/') {
                    int top = deck.top();
                    deck.pop();
                    deck.push(top / num);
                } else if (op == '+') {
                    deck.push(num);
                } else if (op == '-') {
                    deck.push(-num);
                }
                op = c;
                num = 0;
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
    