class TaskManager 
{
    public:
    TaskManager(vector<vector<int>>& tasks) 
    {   
        for (auto& task : tasks) {
            pq.push(task);
            taskIdLookUpTable[task[1]] = {task[0], task[2]};
        }
    }
    
    void add(int userId, int taskId, int priority) 
    {
        pq.push( {userId, taskId, priority} );
        taskIdLookUpTable[taskId] = {userId, priority};
    }
        
    void edit(int taskId, int newPriority) 
    {
        if (taskIdLookUpTable.count(taskId)) {
            int userId = taskIdLookUpTable[taskId].first;
            pq.push( {userId, taskId, newPriority} );
            taskIdLookUpTable[taskId].second = newPriority;
        }
    }
        
    void rmv(int taskId) 
    {
        taskIdLookUpTable.erase(taskId);
    }
    
    int execTop() 
    {
        // only executes the one with the same priority as in the lookUp table
        while (!pq.empty()) {
            auto top = pq.top();
            int taskId = top[1];
            int userId = top[0];
            int priority = top[2];

            if (taskIdLookUpTable.count(taskId)
            && priority == taskIdLookUpTable[taskId].second && userId == taskIdLookUpTable[taskId].first) {
                taskIdLookUpTable.erase(taskId);
                pq.pop();
                return userId;
            } 
            pq.pop();
        }
        return -1;
    }

    private:
    struct Comp
    {
        bool operator()(const vector<int>& a, const vector<int>& b) const {
            if (a[2] != b[2]) {
                return a[2] < b[2];
            }
            return a[1] < b[1];
        }
    };
    priority_queue<vector<int>, vector<vector<int>>, Comp> pq;
    unordered_map<int, pair<int, int>> taskIdLookUpTable; //  { taskId, {userId, priority} }
};
    
    /**
     * Your TaskManager object will be instantiated and called as such:
     * TaskManager* obj = new TaskManager(tasks);
     * obj->add(userId,taskId,priority);
     * obj->edit(taskId,newPriority);
     * obj->rmv(taskId);
     * int param_4 = obj->execTop();
     */