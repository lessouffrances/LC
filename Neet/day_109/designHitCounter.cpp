class HitCounter 
{
    public:
    HitCounter() {}
    void hit(int timestamp) 
    {
        counter.push(timestamp);
    }
    int getHits(int timestamp) 
    {
        while (!counter.empty() && counter.front() <= timestamp-300) {
            counter.pop();
        }
        return counter.size();
    }
    private:
    queue<int> counter;
};
    
   