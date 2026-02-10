class Solution 
{
    public:
    vector<string> invalidTransactions(vector<string>& transactions) 
    {
        if (transactions.empty()) return {};

        int n = transactions.size();
        vector<bool> isInvalid(n, false);

        for (int i=0; i<n; i++) {
            Transaction trans1 = parseTransaction(transactions[i]);
            if (trans1.amount > 1000) {
                isInvalid[i] = true;
            }

            for (int j=0; j<n; j++) {
                if (i == j) continue;
                Transaction trans2 = parseTransaction(transactions[j]);
                if (abs(trans1.time-trans2.time) <= 60 && trans1.name == trans2.name && trans1.city != trans2.city) {
                    isInvalid[i] = true;
                    isInvalid[j] = true;
                }
            }
        }

        vector<string> res;
        for (int i=0; i<n; i++) {
            if (isInvalid[i]) {
                res.push_back(transactions[i]);
            }
        }

        return res;
    }
    private:
    struct Transaction
    {
        string name;
        int time;
        int amount;
        string city;
    };
    Transaction parseTransaction(const string& trans) 
    {
        Transaction res;
        stringstream ss(trans);
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