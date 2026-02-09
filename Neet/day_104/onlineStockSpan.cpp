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
        deck.push( {price, span });
        return span;
    }
    private:
    stack<pair<int, int>> deck; // { price, span }
};
    
    