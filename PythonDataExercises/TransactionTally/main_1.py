# Problem 1 — CSV: Read & summarise transactions
# You're given this CSV data (imagine it's in a file called transactions.csv):
# date,description,amount,type
# 2024-01-05,Direct deposit,3200.00,credit
# 2024-01-07,Rent,-1500.00,debit
# 2024-01-10,Grocery store,-87.45,debit
# 2024-01-12,Freelance payment,950.00,credit
# 2024-01-15,Electric bill,-112.30,debit
# 2024-01-20,ATM withdrawal,-200.00,debit
# Your task: Write a Python function summarise_transactions(filepath) that reads the CSV and prints:

# Total credits
# Total debits (as a positive number)
# Net balance

# Requirements:
# Use Python's built-in csv module (no pandas)
# Handle the amount column as a float
# Print output like:
# Total credits:  4150.00
# Total debits:   1899.75
# Net balance:    2250.25

# Add two more lines to your output so it prints:
# Total credits:   4150.00
# Total debits:    1899.75
# Net balance:     2250.25
# Credit transactions: 2
# Debit transactions:  4

import csv

def summarize_transactions(filepath):
    # init var
    total_credits = 0.0
    total_debits = 0.0
    credit_count = 0
    debit_count = 0
    net_balance = 0.0

    with open(filepath, newline='') as f:
        reader = csv.DictReader(f)

        for row in reader:
            # print(row)
            amount = float(row['amount'])
            account_type = row['type']
            if account_type == 'debit':
                total_debits += abs(amount)
                debit_count += 1
            else:
                total_credits += amount
                credit_count += 1
        
        net_balance = total_credits - total_debits
    
    print(f"Total Credits: {total_credits:.2f}", end="\n")
    print(f"Total Debits: {total_debits:.2f}", end="\n")
    print(f"Net Balance: {net_balance:.2f}", end="\n")
    
    

def main():
    summarize_transactions(filepath="transactions.csv")
main()