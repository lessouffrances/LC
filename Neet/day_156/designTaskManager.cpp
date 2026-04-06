


// edit -> rmv -> execTop -> add
// 

class TaskManager 
{
    public:
    TaskManager(vector<vector<int>>& tasks) 
    {
        // write all into DB
        for (auto& task : tasks) {
            int userId = task[0];
            int taskId = task[1];
            int priority = task[2];
            indexedByTaskId[taskId] = { userId, priority };
            pq.push( {priority, taskId, userId} );
        }
    }
        
    void add(int userId, int taskId, int priority) 
    {
        indexedByTaskId[taskId] = { userId, priority };
        pq.push( {priority, taskId, userId} );
    }
    
    void edit(int taskId, int newPriority) 
    {
        indexedByTaskId[taskId].second = newPriority;
        int userId = indexedByTaskId[taskId].first;
        pq.push( {newPriority, taskId, userId} ); // just push
    }
    
    void rmv(int taskId) 
    {
        indexedByTaskId.erase(taskId);
    }
    
    int execTop()
    {
        if (pq.empty()) return -1;

        while (!pq.empty()) {
            auto [priority, taskId, _] = pq.top();
            pq.pop();
            if (indexedByTaskId.count(taskId) && priority == indexedByTaskId[taskId].second) {
                int userId = indexedByTaskId[taskId].first;
                rmv(taskId);
                return userId;
            }
        }
        return -1;
    }
    
    private:
    unordered_map<int, pair<int, int>> indexedByTaskId; // taskId : { userId, priority }
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, less<tuple<int, int, int>>> pq;
};
    
    