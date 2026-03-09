
// Time: O(log N) for C++, or O(1)
// Space: O(N), where N is the number of input

class MinStack 
{
    public:
    MinStack() {}
    void push(int val) 
    {
        if (minDeck.empty() || val <= minDeck.top()) {
            minDeck.push(val);
        }
        deck.push(val);
    }
    
    void pop() 
    {
        if (minDeck.top() == deck.top()) minDeck.pop();
        deck.pop();
    }
    
    int top() 
    {
        return deck.top();
    }
    
    int getMin() 
    {
        return minDeck.top();
    }
    private:
    stack<int> deck;
    stack<int> minDeck;
};
    
    