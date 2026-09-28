# transactions = [
#     {"id": 1, "customer_id": "C001", "amount": 54.20, "category": "groceries", "date": "2026-01-03"},
#     {"id": 2, "customer_id": "C001", "amount": 120.00, "category": "dining", "date": "2026-01-07"},
#     {"id": 3, "customer_id": "C001", "amount": 15.00, "category": "groceries", "date": "2026-01-10"},
#     {"id": 4, "customer_id": "C002", "amount": 300.00, "category": "travel", "date": "2026-01-05"},
#     {"id": 5, "customer_id": "C002", "amount": -50.00, "category": "groceries", "date": "2026-01-12"},
#     {"id": 6, "customer_id": "C003", "amount": 45.00, "category": "gas", "date": "2026-01-15"},
# ]

# Groceries: 3% cashback
# Dining: 2% cashback
# Gas: 2% cashback
# All other categories: 1% cashback

# def calculate_rewards(transactions, rates, carryover=None):
#     if carryover is None:
#         carryover = {}
#     customer_category_rewards = {} # { cust : { cat : reward_amt } }

#     for txn in transactions:
#         cust = txn["customer_id"]
#         cat = txn["category"]
#         rate = rates.get(cat, rates["default"])
#         reward = txn["amount"] * rate

#         customer_category_rewards.setdefault(cust, {})
#         customer_category_rewards[cust].setdefault(cat, 0)
#         customer_category_rewards[cust][cat] += reward

#     final_rewards = {}
#     new_carryover = {}

#     for cust, cats in customer_category_rewards.items():
#         final_rewards[cust] = {}
#         for cat, reward in cats.items():
#             prior_carry = carryover.get(cust, {}).get(cat, 0)
#             total = reward + prior_carry

#             if total < 0:
#                 final_rewards[cust][cat] = 0
#                 new_carryover.setdefault(cust, {})[cat] = 0
#             else:
#                 final_rewards[cust][cat] = round(total, 2)
#     return final_rewards, new_carryover


transactions_0 = [
    {"id": 1, "customer_id": "C001", "amount": 54.20, "category": "groceries", "date": "2026-01-03"},
    {"id": 2, "customer_id": "C001", "amount": 120.00, "category": "dining", "date": "2026-01-07"},
    {"id": 3, "customer_id": "C001", "amount": 15.00, "category": "groceries", "date": "2026-01-10"},
    {"id": 4, "customer_id": "C002", "amount": 300.00, "category": "travel", "date": "2026-01-05"},
    {"id": 5, "customer_id": "C002", "amount": -50.00, "category": "groceries", "date": "2026-01-12"},
    {"id": 6, "customer_id": "C003", "amount": 45.00, "category": "gas", "date": "2026-01-15"},
]

transactions_1 = [
    {"id": 1, "customer_id": "C001", "amount": 54.20, "category": "groceries", "date": "2026-01-03"},
    {"id": 2, "customer_id": "C001", "amount": 120.00, "category": "dining", "date": "2026-01-07"},
    {"id": 3, "customer_id": "C001", "amount": 15.00, "category": "groceries", "date": "2026-01-10"},
    {"id": 4, "customer_id": "C002", "amount": 30.00, "category": "gas", "date": "2026-01-12"},
    {"id": 5, "customer_id": "C003", "amount": 45.00, "category": "gas", "date": "2026-01-15"},
]

rates = { "groceries": 0.03, "dining": 0.02, "gas" : 0.02 , "default" : 0.01 } 

def calculate_rewards(transactions, rates, carryover=None):
    if carryover is None:
        carryover = {}

    customer_category_rewards = {}

    for txn in transactions:
        cust = txn["customer_id"]
        cat = txn["category"]
        rate = rates.get(cat, rates["default"])
        reward = txn["amount"] * rate

        customer_category_rewards.setdefault(cust, {})
        customer_category_rewards[cust].setdefault(cat, 0)
        customer_category_rewards[cust][cat] += reward

    final_rewards = {}
    new_carryover = {}
    
    # all customers from this cycle and prev carryover 
    all_customers = set(customer_category_rewards.keys()) | set(carryover.keys())

    for cust in all_customers:
        this_cycle_cats = customer_category_rewards.get(cust, {})
        prev_carryover_cats = carryover.get(cust, {})
        all_cats = set(this_cycle_cats.keys()) | set(prev_carryover_cats.keys())

        final_rewards[cust] = {} # { cat : amt }
        for cat in all_cats:
            curr_reward = this_cycle_cats.get(cat, 0)
            prev_carryover = prev_carryover_cats.get(cat, 0)
            total = curr_reward + prev_carryover
            if total < 0:
                final_rewards[cust][cat] = 0
                new_carryover.setdefault(cust, {})[cat] = total
            else:
                final_rewards[cust][cat] = round(total, 2)

    return final_rewards, new_carryover

def main():
    # Cycle 0
    # for the customer C002, expected: final_rewards for groceries is 0, 
    # and in the new_carryover, expected the amount to be "groceries : -1.50"
    final_rewards_0, new_carryover_0 = calculate_rewards(transactions=transactions_0, rates=rates, carryover=None)
    print(final_rewards_0)
    print(new_carryover_0)
    print("##### cycle 0 ends #####", end='\n\n')

    # Cycle 1
    # given that the C002 has -1.5 in the carryover_0 for groceries, 
    # in transaction_1, C002 only spent 30$ on gas, expect 30 * 0.02 = 0.6$ in rewards for gas, 
    # the carryover for groceries of -1.5 should still exist
    # {'C002': {'groceries': -1.5}, {'gas': 0.6} }
    final_rewards_1, new_carryover_1 = calculate_rewards(transactions=transactions_1, rates=rates, carryover=new_carryover_0)
    print(final_rewards_1)
    print(new_carryover_1)
    print("##### cycle 1 ends #####", end='\n\n')

main()