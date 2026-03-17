
// Time: O(N)
// Space: O(N)
class Solution 
{
    public:
    int evalRPN(vector<string>& tokens) 
    {
        if (tokens.empty()) return 0;

        stack<long> deck;
        for (auto& token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                long b = deck.top();
                deck.pop();
                long a = deck.top();
                deck.pop();

                if (token == "+") {
                    deck.push(a + b);
                } else if (token == "-") {
                    deck.push(a - b);
                } else if (token == "*") {
                    deck.push(a * b);
                } else if (token == "/") {
                    deck.push(a / b);
                }
            } else {
                deck.push(stol(token));
            }
        }
        return deck.top();
    }
};