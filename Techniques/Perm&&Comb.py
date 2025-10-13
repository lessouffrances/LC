from itertools import permutations
from itertools import combinations

def generate_permutations(arr):
    return list(permutations(arr))

# Example usage
arr = [1, 2, 3]
perms = generate_permutations(arr)
print(perms)


def generate_combinations(arr, r):
    return list(combinations(arr, r))

# Example usage
arr = [1, 2, 3]
combos = generate_combinations(arr, 2)  # Change 2 to any desired length
print(combos)

