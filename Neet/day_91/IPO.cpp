class Solution 
{
    public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) 
    {
        if (profits.empty() || capital.empty()) return 0;
        int n = profits.size();

        // build projects 
        vector<pair<int, int>> projects;
        for (int i=0; i<n; i++) {
            pair<int, int> proj = {profits[i], capital[i]};
            projects.push_back(proj);
        }

        // sort the projects: lower cap first
        sort(projects.begin(), projects.end(), [](const auto& a, const auto& b){
            return a.second < b.second;
        });

        // pq of indexes of projects: maxHeap, higher profits on top
        priority_queue<int> pq; 

        int idx = 0;
        // iterate for k times
        // it is a simulation process, the w will change over time
        for (int i=0; i<k; i++) {
            while (idx < n && projects[idx].second <= w) {
                pq.push(projects[idx].first); // push the profit onto the pq
                idx++;
            }
            // cannot afford anyone
            if (pq.empty()) break;

            w += pq.top();
            pq.pop();
        }
        return w;
    }
};