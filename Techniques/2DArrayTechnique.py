import random
def main():
    
    # row: 9   col: 7
    twoDArray = [ [ random.randint(0, 7) for _ in range(7) ] for _ in range(9) ]
    print(twoDArray)


main() 