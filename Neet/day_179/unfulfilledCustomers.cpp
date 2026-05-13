// Problem Statement: Unfulfilled Customers
// Context:
// During a flash sale on Amazon, customers submit requests for a limited quantity of a product. Each request includes: [customerId, quantity, bidAmount, timestamp].
// Items are allocated using these rules:

// Higher bids get priority.
// If multiple customers have the same bid, allocate items in a round-robin manner based on earliest timestamp until all inventory is allocated — one item per customer per round, cycling until either inventory runs out or all their requested quantities are fulfilled.

// Return the IDs of customers who received no items.

// Example:
// requests = [[1,5,5,0], [2,7,8,1], [3,7,5,1], [4,10,3,3]]
// totalInventory = 18

// Output: [4]
// Explanation: The first three requests have a higher bid than the 4th. The total quantity requested by the first three is 19, but only 18 items are available — so after round-robin allocation among them, customer 4 receives nothing.

// Function Description:
// Complete the function getUnfulfilledCustomers with the following parameters:

// int requests[requests[0],...,requests[n-1]]: 2D array where each row is [customerId, quantity, bidAmount, timestamp]
// int totalInventory: total number of items available for allocation
// Returns: list of customer IDs who received no items.

struct Request
{
    // customerId, quantity, bidAmount, timestamp
    int customerId;
    int quantity; 
    int bidAmount;
    int timestamp;
};

class Solution
{
    public:

    vector<int> getUnfulfilledCustomers(vector<vector<int>>& requests, int totalInventory)
    {
        if (requests.empty()) return {};
        vector<Request> wrappedRequests = encapsulateRequests(requests);
        int n = requests.size();
        totalInventoryGlobal = totalInventory;

        // group customers with same bidAmount into a group
        // bids are low to high
        map<int, vector<Request>, greater<int>> groupsByBid;
        for (auto& r : wrappedRequests) {
            groupsByBid[r.bidAmount].push_back(r);
        }

        // sort each group by timestamps
        auto comp = [](const Request& a, const Request& b){
            return a.timestamp < b.timestamp;
        };
        for (auto& [ _, requests] : groupsByBid) {
            sort(requests.begin(), requests.end(), comp);
        }

        vector<int> unfulfilled;
        for (auto& [ _, requests] : groupsByBid) {
            vector<int> partUnfulfilled = fulfillOneGroup(requests);
            unfulfilled.insert(unfulfilled.end(), partUnfulfilled.begin(), partUnfulfilled.end());
        }
        return unfulfilled;
    }

    private:
    int totalInventoryGlobal;

    // return a list of customerIds that are not fullfilled.
    vector<int> fulfillOneGroup(vector<Request>& requests) 
    {
        int n = requests.size();
        vector<int> allocated(n, 0);

        bool proceed = true;
        while (totalInventoryGlobal > 0 && proceed) {
            proceed = false;
            for (int i=0; i<n && totalInventoryGlobal>0; i++) {
                if (allocated[i] < requests[i].quantity) {
                    allocated[i]++;
                    totalInventoryGlobal--;
                    proceed = true;
                }
            }
        }

        vector<int> unfulfilled;
        for (int i=0; i<n; i++) {
            if (allocated[i] == 0) unfulfilled.push_back(requests[i].customerId);
        }
        return unfulfilled;
    }

    vector<Request> encapsulateRequests(vector<vector<int>>& requests) 
    {
        if (requests.empty()) return {};

        vector<Request> res;
        for (auto& r : requests) {
            Request request;
            request.customerId = r[0];
            request.quantity = r[1];
            request.bidAmount = r[2];
            request.timestamp = r[3];
            res.push_back(request);
        }
        return res;
    }
};