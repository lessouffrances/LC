from collections import deque

class Solution(object):
    def coinChange(self, coins, amount):
        if not coins:
            return -1

        q = deque()
        q.append(0)
        visited = set()
        visited.add(0)

        num_of_coins = 0
        while q:
            size = len(q)
            for _ in range(size):
                curr_amount = q[0]
                q.popleft()

                if curr_amount == amount:
                    return num_of_coins
                
                for currency in coins:
                    next_amount = curr_amount + currency
                    if next_amount > amount or next_amount in visited:
                        continue

                    q.append(next_amount)
                    visited.add(next_amount)
            num_of_coins += 1

        return -1


