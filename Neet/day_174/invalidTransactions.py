class Solution(object):
    def invalidTransactions(self, transactions):
        if not transactions:
            return []

        n = len(transactions)
        invalid = [False] * n

        for i in range(n):
            trans1 = self.parseTransaction(transactions[i])
            if trans1['amount'] > 1000:
                invalid[i] = True
                continue

            for j in range(n):
                if i == j: continue
                trans2 = self.parseTransaction(transactions[j])

                if trans1['name'] == trans2['name'] and trans1['city'] != trans2['city'] and abs(trans1['time']-trans2['time']) <= 60:
                    invalid[i] = True
                    invalid[j] = True

        # populate the res
        res = []
        for i in range(n):
            if invalid[i]:
                res.append(transactions[i])
        return res          


    def parseTransaction(self, s):
        parts = s.split(',')
        return {
            'name': parts[0],
            'time' :int(parts[1]),
            'amount' : int(parts[2]),
            'city' : parts[3]
        }

        