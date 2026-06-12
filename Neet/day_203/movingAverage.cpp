class MovingAverage 
{
    public:
    MovingAverage(int size) 
    {
        // the size of the MovingAverage
        capacity = size;
    }
    
    double next(int val) 
    {
        if (q.size() == capacity) {
            int toRemove = q.front();
            q.pop();
            currSum -= toRemove;
        }
        q.push(val);
        currSum += val;
        return (double)currSum / q.size();
    }
    private:
    queue<int> q;
    int currSum = 0;
    int capacity;
};
