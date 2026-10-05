customers = [
    {"customer_id": "C500", "credit_score": 720, "current_balance": 0,    "account_age_years": 1, "avg_monthly_spend": 50,   "late_payments_last_12mo": 0},
    {"customer_id": "C501", "credit_score": 680, "current_balance": 0,    "account_age_years": 7, "avg_monthly_spend": 3000, "late_payments_last_12mo": 0},
    {"customer_id": "C502", "credit_score": 710, "current_balance": 1200, "account_age_years": 5, "avg_monthly_spend": 2500, "late_payments_last_12mo": 0},
    {"customer_id": "C503", "credit_score": 705, "current_balance": 0,    "account_age_years": 2, "avg_monthly_spend": 100,  "late_payments_last_12mo": 1},
]

# CREDIT_SCORE_MIN = 300
# CREDIT_SCORE_MAX = 850
# ACCOUNT_AGE_CAP = 10
# SPEND_CAP = 3000

# CREDIT_SCORE_WEIGHT = 0.5
# ACCOUNT_AGE_WEIGHT = 0.2
# SPEND_WEIGHT = 0.3

def determine_offer_eligibility(customer):
    cust_id = customer["customer_id"] # str
    credit_score = customer["credit_score"] # int
    curr_balance = customer["current_balance"] # int
    account_age = customer["account_age_years"] # int
    avg_monthly_spending = customer["avg_monthly_spend"] # int
    late_payment_last_12mo =  customer["late_payments_last_12mo"] # int

    credit_score_norm = (credit_score - 300) / (850 - 300)
    account_age_norm = min(account_age, 10) / 10
    avg_monthly_spending_norm = min(avg_monthly_spending, 3000) / 3000

    score = 0.5 * credit_score_norm + 0.2 * account_age_norm + 0.3 * avg_monthly_spending_norm

    # a hard gate
    if late_payment_last_12mo > 0:
        return (round(score, 2), "decline")
    
    if score > 0.45:
        return (round(score, 2), "offer")
    return (round(score, 2), "decline")


for cust in customers:
    print(determine_offer_eligibility(cust), end="\n\n")
