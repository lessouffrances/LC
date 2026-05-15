class Solution(object):
    def getUnfulfilledCustomers(self, requests, total_inventory):
        if not requests:
            return []
        self.total_inventory_global = total_inventory
        wrapped_requests = self.encapsulateRequests(requests)

        group_by_bid_amount = {}
        for r in wrapped_requests:
            if r['bid_amount'] not in group_by_bid_amount:
                group_by_bid_amount[r['bid_amount']] = []
            group_by_bid_amount[r['bid_amount']].append(r)
        # sort the groups by bid high to low
        group_by_bid_amount = dict(sorted(group_by_bid_amount.items(), key=lambda x: x[0], reverse=True))
        for _, requests in group_by_bid_amount.items():
            requests.sort(key=lambda x:x['timestamp'])
        

        unfulfilled = []
        for _, requests in group_by_bid_amount.items():
            part_unfulfilled = self.fulfillOneGroup(requests)
            unfulfilled.extend(part_unfulfilled)

        return unfulfilled    

    def fulfillOneGroup(self, requests):
        if not requests:
            return []
        
        allocated = [0] * len(requests)
        proceed = True
        while proceed and self.total_inventory_global > 0:
            proceed = False
            for i in range(len(requests)):
                if self.total_inventory_global > 0 and requests[i]['quantity'] > 0:
                    allocated[i] += 1
                    requests[i]['quantity'] -= 1
                    self.total_inventory_global -= 1
                    proceed = True
        
        unfulfilled = []
        for i in range(len(requests)):
            if allocated[i] == 0:
                unfulfilled.append(requests[i]['customer_id'])
        return unfulfilled

    def encapsulateRequests(self, requests):
        if not requests:
            return []
        # customer_id, quantity, bid_amount, timestamp
        res = []
        for r in requests:
            res.append( {
                'customer_id': r[0],
                'quantity': r[1],
                'bid_amount': r[2],
                'timestamp': r[3]
            } )
        return res


def test():
    sol = Solution()

    # Example from problem
    # bid=8: customer 2 (qty 7) -> fully fulfilled
    # bid=5: customers 1 (qty 5) and 3 (qty 7), round-robin, 11 items left
    #   round-robin gives: 1,3,1,3,1,3,1,3,1,3,1 -> customer 1 gets 5, customer 3 gets 6
    #   both get at least 1 item -> neither unfulfilled
    # bid=3: customer 4, inventory=0 -> unfulfilled
    result = sol.getUnfulfilledCustomers([[1,5,5,0],[2,7,8,1],[3,7,5,1],[4,10,3,3]], 18)
    assert result == [4], f"Test 1 failed: {result}"

    # Empty requests
    result = sol.getUnfulfilledCustomers([], 10)
    assert result == [], f"Test 2 failed: {result}"

    # Zero inventory — everyone unfulfilled
    result = sol.getUnfulfilledCustomers([[1,5,5,0],[2,3,8,1]], 0)
    assert sorted(result) == [1, 2], f"Test 3 failed: {result}"

    # Enough inventory for everyone
    result = sol.getUnfulfilledCustomers([[1,2,5,0],[2,3,8,1]], 100)
    assert result == [], f"Test 4 failed: {result}"

    # Single customer, exact inventory
    result = sol.getUnfulfilledCustomers([[1,5,5,0]], 5)
    assert result == [], f"Test 5 failed: {result}"

    # Single customer, not enough inventory
    result = sol.getUnfulfilledCustomers([[1,5,5,0]], 3)
    assert result == [], f"Test 6 failed: {result}"  # gets 3 items, still received something

    # Single customer, zero inventory
    result = sol.getUnfulfilledCustomers([[1,5,5,0]], 0)
    assert result == [1], f"Test 7 failed: {result}"

    # Two customers same bid, only enough for one
    # round-robin: customer 1 (ts=0) goes first, gets 1 item, inventory=0
    # customer 2 gets nothing
    result = sol.getUnfulfilledCustomers([[1,5,5,0],[2,5,5,1]], 1)
    assert result == [2], f"Test 8 failed: {result}"

    print("All tests passed.")

test()