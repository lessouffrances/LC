class MovingAverage 
{
    public:
    MovingAverage(int size) 
    {
        capacity = size;
    }
    
    double next(int val) 
    {
        if (q.size() == capacity) {
            int toRemove = q.front();
            currSum -= toRemove;
            q.pop();
        }
        currSum += val;
        q.push(val);
        return (double) currSum / q.size();
    }
    
    private:
    queue<int> q;
    int currSum = 0;
    int capacity = 0;
};
