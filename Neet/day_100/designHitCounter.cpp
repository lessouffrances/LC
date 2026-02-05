class HitCounter 
{
    public:
    HitCounter() {}
    
    void hit(int timestamp) 
    {
        hits.push(timestamp);
    }
    
    int getHits(int timestamp) 
    {
        while (!hits.empty() && hits.front() <= timestamp-300) {
            hits.pop();
        } 
        return hits.size();s
    }

    private:
    queue<int> hits;
};
    
   