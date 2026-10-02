accounts = [
    {"customer_id": "C300", "credit_limit": 5000, "current_balance": 4200, "pending_holds": 300, "transaction_amount": 400},
    {"customer_id": "C301", "credit_limit": 3000, "current_balance": 1000, "pending_holds": 1800, "transaction_amount": 250},
    {"customer_id": "C302", "credit_limit": 10000, "current_balance": 500, "pending_holds": 0, "transaction_amount": 9000},
]

def authorize_transaction(account):
    available_credit = account["credit_limit"] - account["current_balance"] - account["pending_holds"]
    amount = account["transaction_amount"]
    limit = account["credit_limit"]

    ratio = amount / limit

    if amount > available_credit:
        return "decline"
    if ratio > 0.5:
        return "decline"
    return "approve"


#        available_credit  |  transaction_amt  |  credit_limit  | ratio | act
# C300   500                   400                 5000           0.08    approve
# C301   200                   250                 3000           0.083   decline
# C302   9500                  9000                10000          0.9     decline
