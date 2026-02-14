class BrowserHistory 
{
    public:
    BrowserHistory(string homepage) 
    {
        fullHistory.push_back(homepage);
        currIdx = 0;
    }
    
    void visit(string url) 
    {
        fullHistory.erase(fullHistory.begin()+currIdx+1, fullHistory.end());
        fullHistory.push_back(url);
        currIdx++;
    }
    
    string back(int steps) 
    {
        currIdx = max(0, currIdx-steps);
        return fullHistory[currIdx];
    }
    
    string forward(int steps) 
    {
        currIdx = min((int)fullHistory.size()-1, currIdx+steps);
        return fullHistory[currIdx];   
    }
    private:
    vector<string> fullHistory;
    int currIdx;
};
    
   