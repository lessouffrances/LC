class Solution 
{
    public:
    vector<string> findAllRecipes(vector<string>& recipes, 
        vector<vector<string>>& ingredients, vector<string>& supplies) {

        buildGraph(recipes, ingredients);

        // seed all supplies, no indegree
        queue<string> q;
        for (auto& s : supplies) {
            q.push(s);
        }

        // list to set 
        unordered_set<string> recipesSet = unordered_set<string>(recipes.begin(), recipes.end());
        vector<string> res;

        while (!q.empty()) {
            auto currItem = q.front();
            q.pop();
            // if this is a recipe
            if (recipesSet.count(currItem)) res.push_back(currItem);

            for (auto& nextItem : graph[currItem]) {
                indegree[nextItem]--;
                if (indegree[nextItem] == 0) q.push(nextItem);
            }
        }
        return res;
    }

    private:
    unordered_map<string, vector<string>> graph;
    unordered_map<string, int> indegree;

    void buildGraph(vector<string>& recipes, vector<vector<string>>& ingredients)
    {
        // ingredients -> recipes
        // the size of these two arrays should be the same
        for (int i=0; i<recipes.size(); i++) {
            string recipe = recipes[i];
            auto ingredientList = ingredients[i];
            for (auto& ingredient : ingredientList) {
                graph[ingredient].push_back(recipe);
                indegree[recipe]++;
            }
        }
    }
};