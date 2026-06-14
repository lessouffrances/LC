class MinStack 
{
    public:
    MinStack() {}
    
    void push(int value) 
    {
        deck.push(value);
        if (minDeck.empty() || value <= minDeck.top()) {
            minDeck.push(value);
        }
    }
    
    void pop() 
    {
        int toPop = deck.top();
        deck.pop();
        if (toPop == minDeck.top()) {
            minDeck.pop();
        }
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
    
   