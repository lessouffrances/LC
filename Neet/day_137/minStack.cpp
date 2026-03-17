class MinStack 
{
    public:
    MinStack() {}
    void push(int val) 
    {
        // if the minDeck.empty() or the val is smaller
        if (minDeck.empty() || val <= minDeck.top()) {
            minDeck.push(val);
        }
        deck.push(val);
    }
    
    void pop() 
    {
        // see if the deck.top is a match with the minDeck.top
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
    