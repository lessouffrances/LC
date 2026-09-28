# Write a function high_value_customers(customers_filepath, transactions_filepath, threshold) that:
# Loads the customers JSON
# Loads the transactions CSV
# For each customer ID, computes their net balance from transactions (credits minus debits)
# Prints only customers whose net transaction balance exceeds the threshold

import csv
import json

def process_transactions(transactions_filepath) -> dict[str, float]:
    """
    process transactions, and return a transaction map where,
    customer_id : net_balance
    """

    with open(transactions_filepath, newline='') as f:
        reader = csv.DictReader(f)
        customer_map = {}
        for row in reader:
            customer_id = row['customer_id']
            amount = float(row['amount'])
            transaction_type = row['type']
            if customer_id not in customer_map:
                customer_map[customer_id] = 0.0
            if transaction_type == 'credit':
                customer_map[customer_id] += amount
            else: 
                customer_map[customer_id] -= amount
    return customer_map


def process_customers(customers_filepath) -> dict[str, str]:
    '''
    process customers, and return a identity map where,
    customer_id : customer_name
    '''

    identity_map = {}
    with open(customers_filepath) as f:
        data = json.load(f)
        print(data)
        for customer in data['customers']:
            customer_id = customer['id']
            customer_name = customer['name']
            if customer_id not in identity_map:
                identity_map[customer_id] = customer_name
    return identity_map


def high_value_customers(customers_filepath, transactions_filepath, threshold):
    customer_map = process_transactions(transactions_filepath)
    identity_map = process_customers(customers_filepath)

    print("High Rollers: ", end='\n')
    for id, net in customer_map.items():
        if net > threshold:
            name = identity_map[id]
            print(f"   {name} : {net:.2f}")

def main():
    process_transactions(transactions_filepath='transactions.csv')
    process_customers(customers_filepath='customers.json')
    high_value_customers(customers_filepath='customers.json', transactions_filepath='transactions.csv', threshold=1000)
main()