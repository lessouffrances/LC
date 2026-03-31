# Write a function high_value_customers(customers_filepath, transactions_filepath, threshold) that:

# Loads the customers JSON
# Loads the transactions CSV
# For each customer ID, computes their net balance from transactions (credits minus debits)
# Prints only customers whose net transaction balance exceeds the threshold

import csv
import json

def process_transactions(transactions_filepath) -> dict:
    # process transactions
    with open(transactions_filepath, newline='') as f:
        reader = csv.DictReader(f)

        customer_map = {} # id : [ total_debit, total_credit, net_bal ]
        
        # accumulate credit and debit
        for row in reader:
            customer_id = row['customer_id']
            if customer_id not in customer_map:
                customer_map[customer_id] = [0.0, 0.0, 0.0]

            amount = float(row['amount'])
            transactions_type = row['type']

            if  transactions_type == 'debit':
                customer_map[customer_id][0] += amount
            else:
                customer_map[customer_id][1] += amount

        # compute net_bal
        for info in customer_map.values():
            info[2] = info[1] - info[0]
            
    return customer_map


def high_value_customers(customers_filepath, transactions_filepath, threshold):
    # get the {id : [total_debit, total_credit, net_bal] }
    customer_map = process_transactions(transactions_filepath)

    with open(customers_filepath) as f:
        data = json.load(f)

        for record in data["customers"]:
            customer_id = record['id']
            customer_name = record['name']

            for transaction_customer_id, info in customer_map.items():
                if transaction_customer_id == customer_id:
                    net_bal = info[2]
                    if (net_bal > threshold):
                        print(f"{customer_name} : {net_bal}")

def main():

    high_value_customers("customers.json", "transactions.csv", 1000)

main()

        






