class Logger 
{
    public:
    Logger() {}

    bool shouldPrintMessage(int timestamp, string message) 
    {
        if (logger.count(message) && abs(logger[message]-timestamp) < 10) return false;
        logger[message] = timestamp;
        return true;
    }
    private:
    unordered_map<string, int> logger;
    
};
    
    