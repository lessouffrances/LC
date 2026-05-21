import requests
import json

# https://get-auction-winners.replit.app/
url = "https://get-auction-winners.replit.app/api/auction"
SLOTS = 5

# for all productIds
with open('/Users/lessouffrances/Desktop/LC/Neet/day_183/products.json', 'r') as f:
    data = json.load(f)

product_ids = [product['productId'] for product in data['products']]
headers = {
    "Content-Type": "application/json"
}
payload = {
    "ids": product_ids,
    "slots": SLOTS
}

winners_response = requests.post(url, json=payload, headers=headers)
print(winners_response.status_code)

data = winners_response.json()
print(data)
winner_ids = [winner['id'] for winner in data['winners']]

productIds = [1,2,3,4]
winners = [3,4]
def sortByWinners(product_ids, winners):
    # remove winners from productIds
    remaining = [p for p in product_ids if p not in winners]
    # winners first, then remaining
    return winners + remaining

# call 
print(sortByWinners(product_ids=product_ids, winners=winner_ids))  
