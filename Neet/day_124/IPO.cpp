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
            pair<int, int> proj = { profits[i], capital[i] }; // profit : cap
            projects.push_back(proj);
        }

        // sort the projects: lower cap first;
        sort(projects.begin(), projects.end(), [](const auto& a, const auto& b) {
            return a.second < b.second;
        });

        // maxHeap carries profits
        priority_queue<int> pq;

        // because we only have k projects
        int idx = 0;
        for (int i=0; i<k; i++) {
            // push all the projs we can afford now onto pq
            while (idx<n && projects[idx].second <= w) {
                pq.push(projects[idx].first); // all profits, let maxHeap handle it 
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