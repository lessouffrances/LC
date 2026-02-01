class MinStack 
{
    public:
    MinStack() {}
    
    void push(int val) 
    {
        if (minDeck.empty() || val < minDeck.top()) {
            minDeck.push(val);
        }
        deck.push(val);
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
    stack<int> deck;
    stack<int> minDeck;
};

    
    /**
     * Your MinStack object will be instantiated and called as such:
     * MinStack* obj = new MinStack();
     * obj->push(val);
     * obj->pop();
     * int param_3 = obj->top();
     * int param_4 = obj->getMin();
     */