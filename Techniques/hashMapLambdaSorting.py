hashMap = {(-1, 2, 1): 1, (-1, 2, -4): 4, (-1, 1, -4): 5, (2, 1, -4): 2}

# Sort the dictionary by values in ascending order
sorted_hash_map_asc = dict(sorted(hashMap.items(), key=lambda item: item[1]))

print("Sorted in Ascending Order:")
print(sorted_hash_map_asc)

# Sort the dictionary by values in descending order
sorted_hash_map_desc = dict(sorted(hashMap.items(), key=lambda item: item[1], reverse=True))

print("Sorted in Descending Order:")
print(sorted_hash_map_desc)

