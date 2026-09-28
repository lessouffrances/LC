# {
#   "customers": [
#     {"id": "C001", "name": "Alice Wang", "account_type": "checking", "balance": 4200.00},
#     {"id": "C002", "name": "Bob Smith",  "account_type": "savings",  "balance": 15800.50},
#     {"id": "C003", "name": "Carol Lee",  "account_type": "checking", "balance": 730.20},
#     {"id": "C004", "name": "David Kim",  "account_type": "savings",  "balance": 9100.00},
#     {"id": "C005", "name": "Eve Chen",   "account_type": "checking", "balance": 290.75}
#   ]
# }

# **Your task:** Write a function `get_account_summary(filepath, account_type)` that:
# - Reads the JSON file
# - Filters customers by `account_type` (`"checking"` or `"savings"`)
# - Prints each matching customer's name and balance
# - Prints the total balance for that account type

# **Example output for `account_type="checking"`:**
# Checking accounts:
#   Alice Wang       4200.00
#   Carol Lee         730.20
#   Eve Chen          290.75
# Total: 5220.95

import json

def get_account_summary(filepath, account_type):
    with open(filepath) as f:
        data = json.load(f)

        # id : [ name, type, total_balance ]
        customer_checking_map = {} 
        customer_saving_map = {} 

        for account in data['customers']:
            customer_id = account['id']
            customer_account_type = account['account_type']
            customer_name = account['name']
            customer_bal = float(account['balance'])

            if customer_account_type == 'checking':
                if customer_id not in customer_checking_map:
                    customer_checking_map[customer_id] = [customer_name, customer_account_type, 0.0]
                customer_checking_map[customer_id][2] += customer_bal
            else:
                if customer_id not in customer_saving_map:
                    customer_saving_map[customer_id] = [customer_name, customer_account_type, 0.0]
                customer_saving_map[customer_id][2] += customer_bal
        
        if account_type == 'checking':
            print_out_get_account_summary(customer_map=customer_checking_map, account_type='Checking')
        else:
            print_out_get_account_summary(customer_map=customer_saving_map, account_type='Saving')


def print_out_get_account_summary(customer_map, account_type):
    print(f"{account_type}: ", end='\n')

    account_type_global_balance = 0.0
    for _, info in customer_map.items():
        name = info[0]
        total_balance = info[2]
        account_type_global_balance += total_balance
        print(f"   {name} : {total_balance:.2f}", end='\n')
    print(f"Total: {account_type_global_balance:.2f}")

def main():
    get_account_summary(filepath='customers.json', account_type='checking')
main()
