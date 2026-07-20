class Solution 
{
    public:
    int calPoints(vector<string>& operations) 
    {
        if (operations.empty()) return 0;
        stack<int> deck;

        for (auto& op : operations) {
            if (op == "C") {
                if (!deck.empty()) deck.pop();

            } else if (op == "D") {
                if (!deck.empty()) {
                    deck.push(deck.top() * 2);
                }
            } else if (op == "+") {
                if (!deck.empty()) {
                    int firstNum = deck.top();
                    deck.pop();
                    int secondNum = deck.top();
                    deck.push(firstNum);
                    deck.push(firstNum + secondNum);
                }
            } else {
                deck.push(stoi(op));
            }
        }

        int sum = 0;
        while (!deck.empty()) {
            sum += deck.top();
            deck.pop();
        }
        return sum;
    }
};