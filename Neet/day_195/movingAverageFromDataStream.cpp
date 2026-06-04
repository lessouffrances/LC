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
            int toPop = q.front();
            currSumOfWindow -= toPop;
            q.pop();
        }
        currSumOfWindow += val;
        q.push(val);

        return (double)currSumOfWindow / q.size();
    }

    private:
    int currSumOfWindow = 0;
    int capacity;
    queue<int> q;
};
    
   