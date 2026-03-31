# {
#   "customers": [
#     {"id": "C001", "name": "Alice Wang", "account_type": "checking", "balance": 4200.00},
#     {"id": "C002", "name": "Bob Smith",  "account_type": "savings",  "balance": 15800.50},
#     {"id": "C003", "name": "Carol Lee",  "account_type": "checking", "balance": 730.20},
#     {"id": "C004", "name": "David Kim",  "account_type": "savings",  "balance": 9100.00},
#     {"id": "C005", "name": "Eve Chen",   "account_type": "checking", "balance": 290.75}
#   ]
# }
# ```

# **Your task:** Write a function `get_account_summary(filepath, account_type)` that:
# - Reads the JSON file
# - Filters customers by `account_type` (`"checking"` or `"savings"`)
# - Prints each matching customer's name and balance
# - Prints the total balance for that account type

# **Example output for `account_type="checking"`:**
# ```
# Checking accounts:
#   Alice Wang       4200.00
#   Carol Lee         730.20
#   Eve Chen          290.75
# Total: 5220.95

import json

def get_customer_map(filepath):
    with open(filepath) as f:
        reader = json.load(f)
        # print(reader)
        # treat the reader as Python Dict

        customers_list = reader["customers"]
        customer_map = {} # id : [total_checking, total_saving, name]

        for customer in customers_list:
            # initialize the format of the value
            customer_map[customer['id']] = [0.0, 0.0, customer['name']]

            if customer['account_type'] == 'checking':
                customer_map[customer['id']][0] += customer['balance']
            else:
                customer_map[customer['id']][1] += customer['balance']

        return customer_map

def get_account_summary(filepath, account_type):
    customer_map = get_customer_map(filepath)

    if account_type == 'checking':
        print("Checking Account: ", end='\n')
        for _, info in customer_map.items():
            name = info[2]
            total_checking = info[0]
            if total_checking != 0.0:
                print(f" {name}    {total_checking}")
            
    else:
        print("Saving Account: ", end='\n')
        for _, info in customer_map.items():
            name = info[2]
            total_saving = info[1]
            if total_saving != 0.0:
                print(f" {name}    {total_saving}")

def main():
    get_account_summary('customers.json', account_type='checking')
    get_account_summary('customers.json', account_type='saving')
main()