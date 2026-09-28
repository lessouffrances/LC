transaction_history = {
    "C010": [45.00, 12.50, 8.00, 60.00, 22.00],
    "C020" : [50.00] * 11
}
demographic_baseline = {"mean": 80.00, "std_dev": 40.00}

def is_amount_suspicious(customer_id, amount, transaction_history, demographic_baseline):
    history = transaction_history.get(customer_id, [])

    if len(history) >= 10:
        mean = sum(history) / len(history)
        variance = sum((x - mean) ** 2 for x in history) / len(history)
        std_dev = variance ** 0.5
        if std_dev != 0:
            z_score = (amount - mean) / std_dev
        else:
            return True if amount != mean else False
    else:
        mean = demographic_baseline["mean"]
        std_dev = demographic_baseline["std_dev"]
        z_score = (amount - mean) / std_dev
    return z_score > 3

def main():
    # flag = is_amount_suspicious(customer_id="C010", amount=1200, transaction_history=transaction_history, demographic_baseline=demographic_baseline)
    # flag = is_amount_suspicious(customer_id="C099", amount=500, transaction_history=transaction_history, demographic_baseline=demographic_baseline)
    flag = is_amount_suspicious(customer_id="C020", amount=55, transaction_history=transaction_history, demographic_baseline=demographic_baseline)
    print(flag)

main()