# Write a function high_value_customers(customers_filepath, transactions_filepath, threshold) that:

# Loads the customers JSON
# Loads the transactions CSV
# For each customer ID, computes their net balance from transactions (credits minus debits)
# Prints only customers whose net transaction balance exceeds the threshold

import json
import csv

class High_Value_Solution(object):
    def high_value_customers(self, customers_filepath, transactions_filepath, threshold):

        customer_id_to_name = self.build_customer_id_to_name(customers_filepath=customers_filepath)

        with open(transactions_filepath) as f:
            data = csv.DictReader(f)

            id_to_val = {}
            for row in data:
                customer_id = row['customer_id']
                amount = float(row['amount'])
                transaction_type = row['type']
                if customer_id not in id_to_val:
                    id_to_val[customer_id] = 0
                    
                if transaction_type == 'debit':
                    id_to_val[customer_id] -= amount
                else:
                    id_to_val[customer_id] += amount
        
        print("High Value Customers: ", end='\n')
        for id, val in id_to_val.items():
            if id not in customer_id_to_name: 
                print("error, customer id not found!")
                continue
            if val <= threshold: continue
            name = customer_id_to_name[id]
            print(f"    {name}: {val:.2f} ", end='\n')


    def build_customer_id_to_name(self, customers_filepath):
        """
        type: customers_filepath: json
        rtype: map
        """
        with open(customers_filepath) as f:
            data = json.load(f)
            customer_id_to_name = {}
            for account in data['customers']:
                customer_id = account['id']
                customer_name = account['name']
                customer_id_to_name[customer_id] = customer_name
        return customer_id_to_name

def main():
    sol = High_Value_Solution()
    sol.high_value_customers(customers_filepath='customers.json', transactions_filepath='transactions.csv', threshold=1000)
main()




