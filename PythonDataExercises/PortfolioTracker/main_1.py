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
    def __init__(self, ticker: str, shares: int, purchase_price: float) -> None:
        self.ticker = ticker
        self.shares = shares
        self.purchase_price = purchase_price

    def compute_current_value(self, current_price: float):
        return current_price * self.shares 

    def compute_gain_loss(self, current_price: float):
        net = current_price - self.purchase_price
        return net * self.shares 


class Client:
    def __init__(self, id: str, name: str, collection_of_holdings: list[Holding]) -> None:
        self.id = id
        self.name = name
        self.collection_of_holdings = collection_of_holdings
    
    def compute_total_value(self, price_map):
        total_value = 0.0
        for holding in self.collection_of_holdings:
            ticker = holding.ticker
            current_price = price_map[ticker]
            total_value += holding.compute_current_value(current_price)
        return total_value

    def compute_total_gain_loss(self, price_map):
        total_gain_loss = 0.0
        for holding in self.collection_of_holdings:
            ticker = holding.ticker
            current_price = price_map[ticker]
            total_gain_loss += holding.compute_gain_loss(current_price)
        return total_gain_loss


def process_clients(clients_filepath) -> list[Client]:
    '''
    process the portfolio json obj
    use Client class to encapsulate the client and 
    use Holding class to encapsulate holdings
    return a list of Client objs
    '''
    with open(clients_filepath) as f:
        data = json.load(f)

        clients = []
        for client in data['clients']:
            client_id = client['id']
            client_name = client['name']
            client_holdings = client['holdings']

            holdings = []
            for holding in client_holdings:
                holding_ticker = holding['ticker']
                holding_shares = int(holding['shares'])
                holding_purchase_price = float(holding['purchase_price'])

                holding = Holding(holding_ticker, holding_shares, holding_purchase_price)
                holdings.append(holding)
            
            wrapped_client = Client(client_id, client_name, holdings)
            clients.append(wrapped_client)
        
        return clients


def process_price_map(prices_filepath) -> dict[str, float]:
    '''
    return a map which maps ticker to current price
    '''

    with open(prices_filepath, newline='') as f:
        reader = csv.DictReader(f)
        price_map = {}
        for row in reader:
            ticker = row['ticker']
            current_price = float(row['current_price'])
            price_map[ticker] = current_price
    return price_map


def load_portfolio(clients_filepath, prices_filepath):
    price_map = process_price_map(prices_filepath='prices.csv')
    clients = process_clients(clients_filepath='portfolio.json')

    for client in clients:
        name = client.name
        print(f"{name} :", end='\n')
        for holding in client.collection_of_holdings:
            ticker = holding.ticker
            shares = holding.shares
            current_price = price_map[ticker]

            current_value = holding.compute_current_value(current_price)
            gain_loss = holding.compute_gain_loss(current_price)
            print(f"   {ticker}  {shares} shares  {current_value:.2f}  {gain_loss:.2f}", end='\n')
        
        client_total_value = client.compute_total_value(price_map)
        client_total_gain_loss = client.compute_total_gain_loss(price_map)
        print(f"Total Value: {client_total_value:.2f}  Total Gain\Loss: {client_total_gain_loss:.2f}", end='\n\n')


def main():
    load_portfolio(clients_filepath='portfolio.json', prices_filepath='prices.csv')
main()