class MinStack 
{
    public:
    MinStack() {}
        
    void push(int val) 
    {
        deck.push(val);
        if (minDeck.empty() || val <= minDeck.top()) {
            minDeck.push(val);
        }
    }
        
    void pop() 
    {
        if (deck.top() == minDeck.top()) {
            minDeck.pop();
        }
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
    stack<int> minDeck;
    stack<int> deck;

};
    
    