
customers = [
    {"customer_id": "C100", "credit_limit": 5000,  "avg_balance": 4200, "payment_history": "on_time",  "account_age_years": 6},
    {"customer_id": "C101", "credit_limit": 10000, "avg_balance": 500,  "payment_history": "on_time",  "account_age_years": 2},
    {"customer_id": "C102", "credit_limit": 2000,  "avg_balance": 1900, "payment_history": "on_time",  "account_age_years": 8},
    {"customer_id": "C103", "credit_limit": 15000, "avg_balance": 300,  "payment_history": "late_once", "account_age_years": 1},
]

def calculate_credit_limit_adjustment(customer):
    balance = customer["avg_balance"] # 1900
    limit = customer["credit_limit"] # 2000
    payment_history = customer["payment_history"] # on_time
    account_age = customer["account_age_years"] # 8

    utilization = balance / limit # 0.95

    # classify utilization band
    if utilization >= 0.70:
        util_band = "high" # high
    elif utilization < 0.20:
        util_band = "low" 
    else:
        util_band = "middle"

    age_band = "long" if account_age >= 5 else "short" # long

    # Step 1: early exit — not enough signal either way
    if util_band == "low" and age_band == "short": 
        return "unchanged", None

    # Step 2: scoring
    payment_score = -3 if payment_history == "bad" else 2  # treating "late_once" as bad for now # 2
    utilization_multiplier = {"high": 1.0, "middle": 0.6, "low": 0.4}[util_band] # 1.0
    age_multiplier = 1.5 if age_band == "long" else 1.0 # 1.5

    total = payment_score * utilization_multiplier * age_multiplier # 2 * 1.0 * 1.5 = 3.0

    # Step 3: map score to action (placeholder static thresholds)
    if total >= 2:
        action = "increase"
    elif total <= -2:
        action = "decrease"
    else:
        action = "unchanged"

    return action, round(total, 2)

def main():
    for c in customers:
        action, score = calculate_credit_limit_adjustment(c)
        print(c["customer_id"], "->", action, score)
main()