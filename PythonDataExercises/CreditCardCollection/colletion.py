customers = [
    {"customer_id": "C200", "days_late": 65, "missed_payments_last_12mo": 1, "current_balance": 1200, "resolved_within_grace": False},
    {"customer_id": "C201", "days_late": 35, "missed_payments_last_12mo": 5, "current_balance": 8000, "resolved_within_grace": False},
    {"customer_id": "C202", "days_late": 62, "missed_payments_last_12mo": 1, "current_balance": 300,  "resolved_within_grace": True},
    {"customer_id": "C203", "days_late": 5,  "missed_payments_last_12mo": 1, "current_balance": 500,  "resolved_within_grace": False},
    {"customer_id": "H_A", "days_late": 5, "missed_payments_last_12mo": 10, "current_balance": 0, "resolved_within_grace": False},
    {"customer_id": "H_B", "days_late": 0, "missed_payments_last_12mo": 10, "current_balance": 0, "resolved_within_grace": False}
]

def determine_collections_action(customer):
    days_late = customer["days_late"]
    missed_payments = customer["missed_payments_last_12mo"]
    resolved = customer["resolved_within_grace"]

    resolved_multiplier = 0.3 if resolved else 1.5
    risk_score = (days_late * resolved_multiplier) + (missed_payments * 12)

    if risk_score >= 100:
        action = "refer_agency"
    elif risk_score >= 30:
        action = "phone_call"
    else:
        action = "email_reminder"

    return action, round(risk_score, 1)

for c in customers:
    action, score = determine_collections_action(c)
    print(c["customer_id"], "->", action, score)