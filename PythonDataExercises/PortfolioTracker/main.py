# Your task: Design and implement two classes, then use them to print a portfolio report.
# Holding class:

# Stores ticker, shares, purchase_price
# Has a method current_value(current_price) → returns shares × current_price
# Has a method gain_loss(current_price) → returns current_value - (shares × purchase_price)

# Client class:

# Stores id, name, and a list of Holding objects
# Has a method total_value(price_map) → returns sum of all holdings' current values
# Has a method total_gain_loss(price_map) → returns sum of all holdings' gain/loss

# Then write load_portfolio(clients_filepath, prices_filepath) that loads both files, builds Client and Holding objects, and prints:
# Alice Wang (P001)
#   AAPL      10 shares    1895.00   gain:  395.00
#   GOOGL      5 shares   15500.00   gain:  1500.00
#   TSLA       8 shares    5200.00   loss: -400.00
#   Total value: 22595.00   Total gain/loss: 1495.00

# Bob Smith (P002)
#   ...

import csv
import json

class Holding:
    def __init__(self, ticker: str, shares: int, purchase_price: float):
        self.ticker = ticker
        self.shares = shares
        self.purchase_price = purchase_price

    def compute_current_value(self, current_price):
        return self.shares * current_price

    def compute_gain_loss(self, current_price):
        current_value = self.compute_current_value(current_price)
        return current_value - (self.shares * self.purchase_price)


class Client:
    def __init__(self, id, name, holdings) -> None:
        self.id = id
        self.name = name
        self.holdings = holdings
    
    def compute_total_value(self, price_map):
        total_value = 0
        for holding in self.holdings:
            current_price = price_map[holding.ticker]
            total_value += holding.compute_current_value(current_price)

        return total_value

    def compute_total_gain_loss(self, price_map):
        total_gain_loss = 0
        for holding in self.holdings:
            current_price = price_map[holding.ticker]
            total_gain_loss += holding.compute_gain_loss(current_price)

        return total_gain_loss


def process_clients(clients_filepath):
    with open(clients_filepath) as f:
        data = json.load(f)

        list_clients = []
        for client_info in data['clients']:
            client_id = client_info['id']
            client_name = client_info['name']
            client_holdings = client_info['holdings']

            collection_holding = []
            for holding_info in client_holdings:
                ticker = holding_info['ticker']
                shares = holding_info['shares']
                purchase_price = holding_info['purchase_price']
                holding_obj = Holding(ticker, shares, purchase_price)
                collection_holding.append(holding_obj)

            client_obj = Client(client_id, client_name, collection_holding)
            list_clients.append(client_obj)

        return list_clients


def load_portfolio(clients_filepath, prices_filepath):
    # build price_map
    price_map = {}
    with open(prices_filepath, newline='') as f:
        reader = csv.DictReader(f)
        for row in reader:
            ticker = row['ticker']
            current_price = row['current_price']
            price_map[ticker] = float(current_price)

    list_clients = process_clients(clients_filepath)
    for client in list_clients:
        print(f"{client.name} ({client.id})", end='\n')
        list_holdings = client.holdings
        for holding in list_holdings:
            ticker = holding.ticker
            current_price = price_map[ticker]
            current_value = holding.compute_current_value(current_price)
            gain_loss = holding.compute_gain_loss(current_price)

            if gain_loss > 0:
                print(f"{holding.ticker}   {holding.shares} shares   {current_value:.2f}   gain: {gain_loss:.2f}", end='\n')
            else:
                print(f"{holding.ticker}   {holding.shares} shares   {current_value:.2f}   loss: {gain_loss:.2f}", end='\n')
        
        total_value = client.compute_total_value(price_map)
        total_gain_loss = client.compute_total_gain_loss(price_map)
        print(f"Total Value: {total_value:.2f}, Total gain/loss: {total_gain_loss:.2f}", end='\n\n')
             

def main():
    load_portfolio("portfolio.json", "prices.csv")
main()
