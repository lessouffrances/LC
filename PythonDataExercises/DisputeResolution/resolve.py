disputes = [
    {"customer_id": "C400", "dispute_amount": 45,  "disputes_last_6mo": 0, "disputes_found_invalid_last_6mo": 0},
    {"customer_id": "C401", "dispute_amount": 80,  "disputes_last_6mo": 6, "disputes_found_invalid_last_6mo": 5},
    {"customer_id": "C402", "dispute_amount": 350, "disputes_last_6mo": 1, "disputes_found_invalid_last_6mo": 0},
    {"customer_id": "C403", "dispute_amount": 95,  "disputes_last_6mo": 2, "disputes_found_invalid_last_6mo": 0},
]

def determine_dispute_action(dispute):
    cust_id = dispute["customer_id"] # str
    dispute_amount = dispute["dispute_amount"] # int
    disputes_last_6mo = dispute["disputes_last_6mo"] # int
    disputes_found_invalid_last_6mo = dispute["disputes_found_invalid_last_6mo"] # int

    score = 70 * disputes_found_invalid_last_6mo + dispute_amount

    if score > 223:
        return "hold"
    return "provision"

def determine_dispute_action(dispute):
    cust_id = dispute["customer_id"] # str
    dispute_amount = dispute["dispute_amount"] # int
    disputes_last_6mo = dispute["disputes_last_6mo"] # int
    disputes_found_invalid_last_6mo = dispute["disputes_found_invalid_last_6mo"] # int

    if disputes_last_6mo == 0:
        score = dispute["dispute_amount"]
    elif disputes_last_6mo >= 3:
        invalid_rate = disputes_found_invalid_last_6mo / disputes_last_6mo
        score = 200 * invalid_rate + dispute["dispute_amount"]
    else: 
        score = 70 * disputes_found_invalid_last_6mo + dispute_amount

    if score > 223:
        return "hold"
    return "provision"

for d in disputes:
    print(d["customer_id"], "->", determine_dispute_action(d), end="\n")
    


