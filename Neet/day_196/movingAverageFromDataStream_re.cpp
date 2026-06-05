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
            q.pop();
            currSum -= toRemove;
        }

        q.push(val);
        currSum += val;
        return (double) currSum / q.size(); 
    }

    private:
    int currSum = 0;
    int capacity = 0;
    queue<int> q;
};
    
   