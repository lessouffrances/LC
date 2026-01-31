class Solution 
{
    public:
    vector<string> invalidTransactions(vector<string>& transactions) 
    {
        if (transactions.empty()) return {};
        int n = transactions.size();
        vector<bool> invalid(n, false);

        // parse all trans
        vector<Transaction> parsedTransactions;
        for (int i=0; i<n; i++) {
            parsedTransactions.push_back(toTransaction(transactions[i]));
        }

        // check and mark invalid
        for (int i=0; i<n; i++) {
            if (parsedTransactions[i].amount > 1000) {
                invalid[i] = true;
            }

            for (int j=0; j<n; j++) {
                if (i == j) continue;
                if (parsedTransactions[i].name == parsedTransactions[j].name 
                    && parsedTransactions[i].city != parsedTransactions[j].city 
                    && abs(parsedTransactions[i].time-parsedTransactions[j].time) <= 60)
                    {
                        invalid[i] = true;
                        invalid[j] = true;
                    }
            }
        }

        vector<string> res;
        for (int i=0; i<n; i++) {
            if (invalid[i] == true) {
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
    }

    Transaction parse(const string& trans)
    {
        Transaction res;
        stringstream ss(trans);
        string token;

        getline(ss, res.name, ',' );
        getline(ss, token, ',');
        res.time = stoi(token);
        getline(ss, token, ',');
        res.amount = stoi(token);
        getline(ss, res.city, ',');

        return res;
    }
};