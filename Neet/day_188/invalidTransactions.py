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
                
            for j in range(i+1, n):
                if i == j: continue;
                trans2 = self.parseTransaction(transactions[j])
                if trans1['name'] == trans2['name'] and abs(trans2['time']-trans1['time']) <= 60 and trans1['city'] != trans2['city']:
                    invalid[i] = True
                    invalid[j] = True
        
        # populate the res
        res = []
        for i in range(n):
            if invalid[i] == True:
                res.append(transactions[i])
                
        return res

    def parseTransaction(self, transaction):
        name, time, amount, city = transaction.split(',')

        time = int(time)
        amount = int(amount)
        return {
            'name': name,
            'time': time,
            'amount': amount, 
            'city': city
        }
