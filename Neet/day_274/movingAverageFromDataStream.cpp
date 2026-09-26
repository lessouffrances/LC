class MovingAverage 
{
    public:
    MovingAverage(int size) 
    {
        this->size = size;
    }
    
    double next(int val) 
    {
        currSum += val;
        q.push(val);

        if (q.size() > size) {
            currSum -= q.front();
            q.pop();
        }

        return (double)currSum / q.size();
    }

    private:
    int size;
    int currSum = 0;
    queue<int> q;
};
    
    