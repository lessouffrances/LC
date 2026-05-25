class RecentCounter 
{
    public:
    RecentCounter() {}
    
    int ping(int t) 
    {
        while (record.front() < t-3000) record.pop();
        record.push(t);
        return record.size();
    }
    private:
    queue<int> record;
};
    
   