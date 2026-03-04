


// Time: O (V + E)
// Space: 3 input lists
class Solution
{
    public:
    Solution (vector<string>& fromCurrency, vector<string>&toCurrency)
    {
        this->fromCurrency = fromCurrency;
        this->toCurrency = toCurrency;
    }

    
    double getConversionRate(const string& currency1, const string& currency2) 
    {
        if (!graph.count(currency1) || !graph.count(currency2)) return -1.0;
        // do BFS
    }

    private:
    vector<string> fromCurrency;
    vector<string> toCurrency;
    vector<double> rates;

    unordered_map<int, vector<pair<strint, int>>> graph; //adjList

    void buildGraph(vector<string>& fromCurrency, vector<string>&toCurrency, 
    vector<double>& rates)
    {
        int n = fromCurrency.size();
        for (int i=0; i<n; i++) {
            string u = fromCurrencyp[i];
            string v = toCurrency[i];
            graph[u].push_back( {v, rates[i]} );;
            graph[v].push_back( {u, 1.0 / rates[i]} );
        }
    }
};