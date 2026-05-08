class Solution 
{
    public:
    vector<string> invalidTransactions(vector<string>& transactions) 
    {
        if (transactions.empty()) return {};
        int n = transactions.size();

        vector<bool> invalid(n, false);
        for (int i=0; i<n; i++) {
            Transaction trans1 = parseTransaction(transactions[i]);
            if (trans1.amount > 1000) invalid[i] = true;

            for (int j=0; j<n; j++) {
                if (i == j) continue;
                Transaction trans2 = parseTransaction(transactions[j]);
                if (trans1.name == trans2.name && trans1.city != trans2.city 
                && abs(trans1.time-trans2.time) <= 60) {
                    invalid[i] = true;
                    invalid[j] = true;
                } 
            }
        }

        // populate the res
        vector<string> res;
        for (int i=0; i<n; i++) {
            if (invalid[i] == true) {
                res.push_back(transactions[i]);
            }
        }
        return res;
    }

    private:
    // "alice,20,800,mtv"
    struct Transaction
    {
        string name;
        int time;
        int amount;
        string city;
    };

    Transaction parseTransaction(const string& s)
    {
        Transaction res;
        stringstream ss(s);
        string token;
        getline(ss, res.name, ',');
        getline(ss, token, ',');
        res.time = stoi(token);
        getline(ss, token, ',');
        res.amount = stoi(token);
        getline(ss, res.city, ',');
        return res;
    }
};