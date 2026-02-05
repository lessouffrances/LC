class StockSpanner 
{
    public:
    StockSpanner() {}
    
    int next(int price) 
    {
        int span = 1;
        while (!deck.empty() && price >= deck.top().first) {
            span += deck.top().second;
            deck.pop();
        }
        deck.push( {price, span} );
        return span;
    }
    private:
    stack<pair<int, int>> deck;
};
    
    /**
     * Your StockSpanner object will be instantiated and called as such:
     * StockSpanner* obj = new StockSpanner();
     * int param_1 = obj->next(price);
     */