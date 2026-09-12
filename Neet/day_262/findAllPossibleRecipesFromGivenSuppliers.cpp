class Solution 
{
    public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) 
    {
        for (string& s : supplies) {
            available.insert(s);
        }

        // seed all recipe idx
        queue<int> q;
        for (int i=0; i<recipes.size(); i++) {
            q.push(i); 
        }

        vector<string> res;
        int lastAvailableSize = -1;
        
        // this while loop continues when there are new recipe can be made
        while ((int)available.size()>lastAvailableSize) {
            // update lastAvailableSize
            lastAvailableSize = available.size();

            int size = q.size();
            for (int i=0; i<size; i++) {
                int currRecipeIdx = q.front();
                q.pop();

                if (canCreate(currRecipeIdx, ingredients)) {
                    // become an ingredient
                    available.insert(recipes[currRecipeIdx]);
                    res.push_back(recipes[currRecipeIdx]);
                } else {
                    // wait in queue
                    q.push(currRecipeIdx);
                }
            }
        }
        return res;
    }

    private:
    unordered_set<string> available;
    bool canCreate(int recipeIdx, vector<vector<string>>& ingredients)
    {
        for (string& ingredient : ingredients[recipeIdx]) {
            if (!available.count(ingredient)) return false;
        }
        return true;
    }
};