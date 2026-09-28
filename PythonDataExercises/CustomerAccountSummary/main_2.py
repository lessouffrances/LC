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
class Account_Summary_Solution(object):
    def get_account_summary(self, filepath, account_type):
        with open(filepath) as f:
            data = json.load(f)

            checking_account_map = {} # [ customer_name, bal ]
            saving_account_map = {}

            # loop thru each account obj
            for account in data['customers']:
                # retrieve the info for each obj
                customer_id = account['id']
                customer_name = account['name']
                customer_account_type = account['account_type']
                account_bal = account['balance']
                
                # branching
                if customer_account_type == "checking":
                    if customer_id not in checking_account_map:
                        checking_account_map[customer_id] = [customer_name, 0]
                    checking_account_map[customer_id][1] += account_bal

                else:
                    if customer_id not in saving_account_map:
                        saving_account_map[customer_id] = [customer_name, 0]
                    saving_account_map[customer_id][1] += account_bal
            
            if account_type == "checking":
                self.print_out_information(account_type, checking_account_map)
            else:
                self.print_out_information(account_type, saving_account_map)
            
    def print_out_information(self, account_type, account_map):
        if account_type == "checking":
            print("Checking accounts: ", end='\n')
        else:
            print("Saving accounts: ", end='\n')

        total_bal = 0
        for _, info in account_map.items():
            customer_name = info[0]
            bal = info[1]
            total_bal += bal
            print(f"    {customer_name}    {bal:.2f}", end='\n')
        print(f"Total: {total_bal:.2f}", end='\n')

def main():
    sol = Account_Summary_Solution()
    sol.get_account_summary(filepath='customers.json', account_type='checking')
main()
